#include "../include/XDFile.h"

#include <string>

#include "../include/MMElement.h"
#include "../crossplatform/XdfStringFormat.h"

namespace dd::libxdf::types {
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
        return *this->children.find(elementHexId)->second;
    }

    MMElement &MMElement::GetElementByUID(uint64_t uid) {
        return *this->children.find(NumToHex(uid))->second;
    }

    MMElement *MMElement::GetElementByName(const std::string &elementName) {
        for (auto &child: this->children) {
            if(child.second->GetName() == elementName) {
                return child.second;
            }
        }

        return nullptr;
    }

    MMAttribute &MMElement::GetAttribute(const std::string &attributeName) {
        return this->attributes.find(attributeName)->second;
    }

    uint64_t MMElement::GetUniqueId() const {
        return this->uniqueId;
    }

    std::string MMElement::GetUniqueHexId() const {
        return format("{:#x}", this->uniqueId);
    }

    void MMElement::InsertAttribute(const MMAttribute &attribute) {
        this->attributes.insert({attribute.name, attribute});
    }

    void MMElement::InsertElement(MMElement *element) {
        this->children.insert({element->GetUniqueHexId(), element});
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
            toStringStream << this->text;

            for (auto &element: this->children) {
                toStringStream << element.second->ToString() << "\t\n";
            }

            toStringStream << "</" << this->name << ">" << std::endl;
        }

        return toStringStream.str();
    }

    void MMElement::SetText(const std::string &newText) {
        this->text = newText;
    }

    //TODO(Demi): Needs implementation desperately
    MMElement::~MMElement() {
        for(const auto& element : this->children) {
            delete element.second;
        }
    }

    std::vector<MMElement *> MMElement::GetAllElements() {
        std::vector<MMElement *> _ret;

        for (const auto &elementPair: children) {
            _ret.emplace_back(elementPair.second);
        }

        return _ret;
    }

    void MMElement::RemoveElement(std::string &uid) {
        this->children.erase(uid);
    }

    void MMElement::RemoveAttribute(std::string &key) {
        this->attributes.erase(key);
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