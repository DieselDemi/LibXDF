#include "../include/XDFile.h"

#include <string>
#include <algorithm>
#include <stdexcept>

#include "../include/MMElement.h"
#include "../crossplatform/XdfStringFormat.h"

namespace dd::libxdf::types {
    namespace {
        std::string EscapeText(const std::string& value) {
            std::string escaped;
            escaped.reserve(value.size());

            for (const char character : value) {
                switch (character) {
                    case '&': escaped += "&amp;"; break;
                    case '<': escaped += "&lt;"; break;
                    case '>': escaped += "&gt;"; break;
                    default: escaped += character; break;
                }
            }

            return escaped;
        }
    }

    MMElement::MMElement(std::string name, enums::ElementType type, std::initializer_list<MMAttribute> attributes, bool displayUID) {
        this->name = std::move(name);
        this->text = "";
        this->uniqueId = XDFile::NextUnique();
        this->elementType = type;

        if(attributes.size() != 0) {
            for (const auto &attr: attributes) {
                this->InsertAttribute(attr);
            }
        }

        if(displayUID) {
            this->InsertAttribute({.name="uniqueid", .value=this->GetUniqueHexId()});
        }
    }

    MMElement::MMElement(std::string name, enums::ElementType type, std::string textValue, bool displayUID) {
        this->name = std::move(name);
        this->text = std::move(textValue);
        this->uniqueId = XDFile::NextUnique();
        this->elementType = type;

        if(displayUID) {
            this->InsertAttribute({.name="uniqueid", .value=this->GetUniqueHexId()});
        }
    }

    MMElement::MMElement(std::string name, enums::ElementType type, bool displayUID) {
        this->name = std::move(name);
        this->uniqueId = XDFile::NextUnique();
        this->elementType = type;

        if(displayUID) {
            this->InsertAttribute({.name="uniqueid", .value=this->GetUniqueHexId()});
        }
    }

    void MMElement::SetName(const std::string &newName) {
        this->name = newName;
    }

    void MMElement::AddElement(MMElement *element) {
        InsertElement(element);
    }

    void MMElement::AddAttribute(const MMAttribute& attribute) {
        InsertAttribute(attribute);
    }

    MMElement &MMElement::GetElementByHexId(const std::string &elementHexId) {
        const auto element = this->children.find(elementHexId);
        if (element == this->children.end()) {
            throw std::out_of_range("XDF element ID not found: " + elementHexId);
        }
        return *element->second;
    }

    MMElement &MMElement::GetElementByUID(uint64_t uid) {
        return GetElementByHexId(NumToHex(uid));
    }

    MMElement *MMElement::GetElementByName(const std::string &elementName) {
        for (auto &child: this->children) {
            if(child.second->GetName() == elementName) {
                return child.second;
            }
        }

        return nullptr;
    }

    const MMElement *MMElement::GetElementByName(const std::string &elementName) const {
        for (const auto *child: this->childOrder) {
            if(child->GetName() == elementName) return child;
        }
        return nullptr;
    }

    MMAttribute &MMElement::GetAttribute(const std::string &attributeName) {
        const auto attribute = this->attributes.find(attributeName);
        if (attribute == this->attributes.end()) {
            throw std::out_of_range("XDF attribute not found: " + attributeName);
        }
        return attribute->second;
    }

    MMAttribute* MMElement::FindAttribute(const std::string& attributeName) {
        const auto attribute = this->attributes.find(attributeName);
        return attribute == this->attributes.end() ? nullptr : &attribute->second;
    }

    const MMAttribute* MMElement::FindAttribute(const std::string& attributeName) const {
        const auto attribute = this->attributes.find(attributeName);
        return attribute == this->attributes.end() ? nullptr : &attribute->second;
    }

    uint64_t MMElement::GetUniqueId() const {
        return this->uniqueId;
    }

    std::string MMElement::GetUniqueHexId() const {
        return format("{:#x}", this->uniqueId);
    }

    void MMElement::InsertAttribute(const MMAttribute &attribute) {
        this->attributes.insert_or_assign(attribute.name, attribute);
    }

    void MMElement::InsertElement(MMElement *element) {
        if (element == nullptr) {
            throw std::invalid_argument("Cannot add a null XDF element");
        }

        while (this->children.contains(element->GetUniqueHexId())) {
            element->SetUniqueId(XDFile::NextUnique());
        }

        this->children.insert({element->GetUniqueHexId(), element});
        this->childOrder.push_back(element);
    }

    void MMElement::SetUniqueId(uint64_t id) {
        this->uniqueId = id;
    }

    std::string MMElement::ToString() { // NOLINT(misc-no-recursion)
        std::stringstream toStringStream;

        toStringStream << "<" << this->name;

        if (!this->attributes.empty()) {
            for (auto &attribute: this->attributes) {
                toStringStream << " " << attribute.second.ToString();
            }
        }

        //Check if element is empty - if it is, quick close it.
        if (this->children.empty() && this->text.empty()) {
            toStringStream << "/>" << std::endl;
            return toStringStream.str();
        } else {
            toStringStream << ">";
            toStringStream << EscapeText(this->text);

            for (auto *element: this->childOrder) {
                toStringStream << element->ToString();
            }

            toStringStream << "</" << this->name << ">" << std::endl;
        }

        return toStringStream.str();
    }

    void MMElement::SetText(const std::string &newText) {
        this->text = newText;
    }

    MMElement::~MMElement() {
        ClearElements();
    }

    std::vector<MMElement *> MMElement::GetAllElements() {
        std::vector<MMElement *> _ret;

        for (auto *element: childOrder) {
            _ret.emplace_back(element);
        }

        return _ret;
    }

    std::vector<const MMElement *> MMElement::GetAllElements() const {
        std::vector<const MMElement *> result;
        result.reserve(childOrder.size());
        for (const auto *element : childOrder) result.push_back(element);
        return result;
    }

    void MMElement::RemoveElement(std::string &uid) {
        const auto element = this->children.find(uid);
        if (element == this->children.end()) {
            return;
        }

        MMElement* removed = element->second;
        this->childOrder.erase(
                std::remove(this->childOrder.begin(), this->childOrder.end(), removed),
                this->childOrder.end());
        this->children.erase(element);
        delete removed;
    }

    void MMElement::RemoveAttribute(std::string &key) {
        this->attributes.erase(key);
    }

    void MMElement::ClearElements() {
        for (auto *element : this->childOrder) {
            delete element;
        }
        this->childOrder.clear();
        this->children.clear();
    }

    void MMElement::ClearAttributes() {
        this->attributes.clear();
    }

    std::vector<MMElement*> MMElement::GetElementsByName(const std::string& elementName) {
        std::vector<MMElement*> matches;
        for (auto *element : this->childOrder) {
            if (element->GetName() == elementName) {
                matches.push_back(element);
            }
        }
        return matches;
    }

    std::vector<const MMElement*> MMElement::GetElementsByName(const std::string& elementName) const {
        std::vector<const MMElement*> matches;
        for (const auto *element : this->childOrder) {
            if (element->GetName() == elementName) matches.push_back(element);
        }
        return matches;
    }

    std::string &MMElement::GetName() const {
        return const_cast<std::string &>(this->name);
    }

    std::string &MMElement::GetInnerText() const {
        return const_cast<std::string &>(this->text);
    }

    enums::ElementType MMElement::GetElementType() {
        return this->elementType;
    }
} // types
