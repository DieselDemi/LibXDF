#include "include/XDFile.h"

#include <fstream>
#include <memory>
#include <set>
#include <string_view>

#include <tinyxml2.h>

#include "exceptions/XdfFileException.h"
#include "include/MMCategory.h"
#include "include/MMDefaultsElement.h"
#include "include/MMEmbeddedData.h"
#include "include/MMMath.h"
#include "include/MMRegion.h"
#include "include/elements/MMXDFAxis.h"
#include "include/elements/MMXDFChecksum.h"
#include "include/elements/MMXDFConstant.h"
#include "include/elements/MMXDFFlag.h"
#include "include/elements/MMXDFFunction.h"
#include "include/elements/MMXDFHeader.h"
#include "include/elements/MMXDFPatch.h"
#include "include/elements/MMXDFPatchEntry.h"
#include "include/elements/MMXDFTable.h"

namespace dd::libxdf {
    namespace {
        using types::MMElement;
        using types::ParsedTag;

        std::unique_ptr<MMElement> CreateElement(std::string_view name) {
            using namespace types;
            using namespace types::elements;

            if (name == "XDFHEADER") return std::make_unique<MMXDFHeader>(ParsedTag{});
            if (name == "XDFCONSTANT") return std::make_unique<MMXDFConstant>(ParsedTag{});
            if (name == "XDFFLAG") return std::make_unique<MMXDFFlag>(ParsedTag{});
            if (name == "XDFTABLE") return std::make_unique<MMXDFTable>(ParsedTag{});
            if (name == "XDFFUNCTION") return std::make_unique<MMXDFFunction>(ParsedTag{});
            if (name == "XDFCHECKSUM") return std::make_unique<MMXDFChecksum>(ParsedTag{});
            if (name == "XDFPATCH") return std::make_unique<MMXDFPatch>(ParsedTag{});
            if (name == "XDFPATCHENTRY") return std::make_unique<MMXDFPatchEntry>(ParsedTag{});
            if (name == "XDFAXIS") return std::make_unique<MMXDFAxis>(ParsedTag{});
            if (name == "EMBEDDEDDATA") return std::make_unique<MMEmbeddedData>(ParsedTag{});
            if (name == "MATH") return std::make_unique<MMMath>(ParsedTag{});
            if (name == "VAR") return std::make_unique<MMVar>(ParsedTag{});
            if (name == "REGION") return std::make_unique<MMRegion>(ParsedTag{});
            if (name == "CATEGORY") return std::make_unique<MMCategory>(ParsedTag{});
            if (name == "DEFAULTS") return std::make_unique<MMDefaultsElement>(ParsedTag{});
            return std::make_unique<MMElement>(std::string(name), types::enums::ElementType::GENERIC);
        }

        std::unique_ptr<MMElement> ParseElement(const tinyxml2::XMLElement& source) {
            auto result = CreateElement(source.Name());

            for (auto* attribute = source.FirstAttribute(); attribute != nullptr; attribute = attribute->Next()) {
                result->AddAttribute({.name = attribute->Name(), .value = attribute->Value()});
            }

            if (source.FirstChildElement() == nullptr && source.GetText() != nullptr) {
                result->SetText(source.GetText());
            }

            for (auto* child = source.FirstChildElement(); child != nullptr; child = child->NextSiblingElement()) {
                result->AddElement(ParseElement(*child).release());
            }

            return result;
        }

        void PopulateRoot(types::elements::XDFRootTag& target, const tinyxml2::XMLDocument& document) {
            const auto* root = document.RootElement();
            if (root == nullptr || std::string_view(root->Name()) != "XDFFORMAT") {
                throw XdfFileException("XDF document root must be XDFFORMAT");
            }

            target.ClearElements();
            target.ClearAttributes();
            target.SetText("");
            target.SetName(root->Name());

            for (auto* attribute = root->FirstAttribute(); attribute != nullptr; attribute = attribute->Next()) {
                target.AddAttribute({.name = attribute->Name(), .value = attribute->Value()});
            }

            for (auto* child = root->FirstChildElement(); child != nullptr; child = child->NextSiblingElement()) {
                target.AddElement(ParseElement(*child).release());
            }
        }

        void CheckParseResult(const tinyxml2::XMLDocument& document, tinyxml2::XMLError result) {
            if (result != tinyxml2::XML_SUCCESS) {
                throw XdfFileException(
                        "Unable to parse XDF XML at line " + std::to_string(document.ErrorLineNum()) +
                        ": " + document.ErrorStr());
            }
        }

        void ValidateElement(const MMElement& element, std::vector<XDFDiagnostic>& diagnostics) {
            if (element.GetName() == "XDFAXIS") {
                const auto* id = element.FindAttribute("id");
                if (id == nullptr || (id->value != "x" && id->value != "y" && id->value != "z" &&
                                      id->value != "X" && id->value != "Y" && id->value != "Z")) {
                    diagnostics.push_back({DiagnosticSeverity::WARNING, "XDFAXIS has a missing or unknown id", &element});
                }

                const auto* countElement = element.GetElementByName("indexcount");
                if (countElement != nullptr) {
                    try {
                        const auto expected = static_cast<std::size_t>(std::stoull(countElement->GetInnerText()));
                        const auto actual = element.GetElementsByName("LABEL").size();
                        if (actual != 0 && actual != expected) {
                            diagnostics.push_back({DiagnosticSeverity::WARNING,
                                                   "XDFAXIS indexcount does not match its LABEL count", &element});
                        }
                    } catch (const std::exception&) {
                        diagnostics.push_back({DiagnosticSeverity::WARNING, "XDFAXIS indexcount is not numeric", &element});
                    }
                }
            }

            if (const auto* embedded = dynamic_cast<const types::MMEmbeddedData*>(&element)) {
                if (!embedded->GetElementSizeBits()) {
                    diagnostics.push_back({DiagnosticSeverity::WARNING,
                                           "EMBEDDEDDATA has a missing or invalid element size", &element});
                }
                if (embedded->FindAttribute("mmedaddress") != nullptr && !embedded->GetAddress()) {
                    diagnostics.push_back({DiagnosticSeverity::WARNING,
                                           "EMBEDDEDDATA has an invalid hexadecimal address", &element});
                }
            }

            for (const auto* child : element.GetAllElements()) ValidateElement(*child, diagnostics);
        }
    }

    void XDFile::ReadFromDisk(const std::string& fileName) {
        tinyxml2::XMLDocument document;
        const auto result = document.LoadFile(fileName.c_str());
        CheckParseResult(document, result);
        PopulateRoot(documentRoot, document);
    }

    void XDFile::ReadFromString(const std::string& xml) {
        tinyxml2::XMLDocument document;
        const auto result = document.Parse(xml.data(), xml.size());
        CheckParseResult(document, result);
        PopulateRoot(documentRoot, document);
    }

    bool XDFile::WriteToDisk(const std::string& fileName) {
        std::ofstream file(fileName, std::ios::binary);

        if(!file.is_open())
            return false;

        file << documentRoot.ToString();
        file.flush();

        return file.good();
    }

    void XDFile::RemoveElement(std::string& uid) {
        this->documentRoot.RemoveElement(uid);
    }

    std::string XDFile::Print() {
        return documentRoot.ToString();
    }

    types::elements::XDFRootTag &XDFile::GetRootTag() {
        return this->documentRoot;
    }

    const types::elements::XDFRootTag &XDFile::GetRootTag() const {
        return this->documentRoot;
    }

    std::vector<XDFDiagnostic> XDFile::Validate() const {
        std::vector<XDFDiagnostic> diagnostics;
        if (documentRoot.FindAttribute("version") == nullptr) {
            diagnostics.push_back({DiagnosticSeverity::ERROR, "XDFFORMAT is missing its version attribute", &documentRoot});
        }

        std::set<std::string> uniqueIds;
        for (const auto* element : documentRoot.GetAllElements()) {
            if (const auto* id = element->FindAttribute("uniqueid"); id != nullptr &&
                id->value != "0" && id->value != "0x0" && id->value != "0x00" && id->value != "0.0000") {
                if (!uniqueIds.insert(id->value).second) {
                    diagnostics.push_back({DiagnosticSeverity::WARNING,
                                           "Duplicate non-placeholder top-level uniqueid: " + id->value, element});
                }
            }
            ValidateElement(*element, diagnostics);
        }
        return diagnostics;
    }

}
