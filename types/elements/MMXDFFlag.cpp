#include "../../include/elements/MMXDFFlag.h"
#include "../../include/MMEmbeddedData.h"
#include "../../crossplatform/XdfStringFormat.h"
#include <charconv>
#include <string_view>

namespace dd::libxdf::types::elements {
    MMXDFFlag::MMXDFFlag(ParsedTag) : MMElement("XDFFLAG", enums::ElementType::FLAG) {}

    MMXDFFlag::MMXDFFlag(MMEmbeddedData *embeddedData, std::string title, std::string description, uint8_t maskValue) :
        MMElement("XDFFLAG", enums::ElementType::FLAG, {}, true) {
        this->InsertElement(new MMElement("title", enums::ElementType::GENERIC, std::move(title)));
        this->InsertElement(new MMElement("description", enums::ElementType::GENERIC, std::move(description)));
        this->InsertElement(embeddedData);
        this->InsertElement(new MMElement("mask", enums::ElementType::GENERIC, format("{:#x}", maskValue)));
    }

    MMEmbeddedData* MMXDFFlag::GetEmbeddedData() {
        return dynamic_cast<MMEmbeddedData*>(GetElementByName("EMBEDDEDDATA"));
    }

    std::optional<uint64_t> MMXDFFlag::GetMask() const {
        auto* mask = const_cast<MMXDFFlag*>(this)->GetElementByName("mask");
        if (mask == nullptr) return std::nullopt;
        std::string_view value = mask->GetInnerText();
        if (value.starts_with("0x") || value.starts_with("0X")) value.remove_prefix(2);
        uint64_t result{};
        const auto parsed = std::from_chars(value.data(), value.data() + value.size(), result, 16);
        if (parsed.ec != std::errc{} || parsed.ptr != value.data() + value.size()) return std::nullopt;
        return result;
    }
} // elements
