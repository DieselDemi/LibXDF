#ifndef XDFCREATOR_MMELEMENT_H
#define XDFCREATOR_MMELEMENT_H

#include <cstdlib>
#include <map>
#include <string>
#include <vector>

#include "MMAttribute.h"
#include "MMTypes.h"

namespace dd::libxdf::types {
    class MMElement {
    public:
        explicit MMElement(std::string name, enums::ElementType type, std::string textValue, bool displayUID = false);
        explicit MMElement(std::string name, enums::ElementType type, std::initializer_list<MMAttribute> attributes, bool displayUID = false);
        explicit MMElement(std::string name, enums::ElementType type, bool displayUID = false);
        ~MMElement();

        void SetUniqueId(uint64_t id);
        void SetName(const std::string& newName);
        void SetText(const std::string& newText);

        [[nodiscard]]
        std::string& GetName() const;

        [[nodiscard]]
        std::string& GetInnerText() const;

        void AddElement(MMElement*);
        void AddAttribute(const MMAttribute&);

        void RemoveElement(std::string& uid);
        void RemoveAttribute(std::string& key);

        MMElement& GetElementByHexId(const std::string& elementHexId);
        MMElement& GetElementByUID(uint64_t uid);
        MMElement* GetElementByName(const std::string& elementName);

        enums::ElementType GetElementType();

        std::vector<MMElement*> GetAllElements();

        MMAttribute& GetAttribute(const std::string& attributeName);
        [[nodiscard]] uint64_t GetUniqueId() const;
        [[nodiscard]] std::string GetUniqueHexId() const;

        virtual std::string ToString();

    protected:
        void InsertAttribute(const MMAttribute& attribute);
        void InsertElement(MMElement* element);

        uint64_t uniqueId;

        std::string name;
        std::string text;
        std::map<std::string, MMElement*> children;
        std::map<std::string, MMAttribute> attributes;

        enums::ElementType elementType;
    };

} // types

#endif //XDFCREATOR_MMELEMENT_H
