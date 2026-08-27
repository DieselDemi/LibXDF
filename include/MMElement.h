#ifndef XDFCREATOR_MMELEMENT_H
#define XDFCREATOR_MMELEMENT_H

#include <cstdlib>
#include <map>
#include <string>
#include <vector>

#include "MMAttribute.h"
#include "MMTypes.h"

namespace dd::libxdf::types {
    struct ParsedTag final {};

    class MMElement {
    public:
        explicit MMElement(std::string name, enums::ElementType type, std::string textValue, bool displayUID = false);
        explicit MMElement(std::string name, enums::ElementType type, std::initializer_list<MMAttribute> attributes, bool displayUID = false);
        explicit MMElement(std::string name, enums::ElementType type, bool displayUID = false);
        virtual ~MMElement();

        MMElement(const MMElement&) = delete;
        MMElement& operator=(const MMElement&) = delete;
        MMElement(MMElement&&) = delete;
        MMElement& operator=(MMElement&&) = delete;

        void SetUniqueId(uint64_t id);
        void SetName(const std::string& newName);
        void SetText(const std::string& newText);

        [[nodiscard]]
        std::string& GetName() const;

        [[nodiscard]]
        std::string& GetInnerText() const;

        void AddElement(MMElement*);
        void AddAttribute(const MMAttribute&);

        void ClearElements();
        void ClearAttributes();

        void RemoveElement(std::string& uid);
        void RemoveAttribute(std::string& key);

        MMElement& GetElementByHexId(const std::string& elementHexId);
        MMElement& GetElementByUID(uint64_t uid);
        MMElement* GetElementByName(const std::string& elementName);
        const MMElement* GetElementByName(const std::string& elementName) const;
        std::vector<MMElement*> GetElementsByName(const std::string& elementName);
        std::vector<const MMElement*> GetElementsByName(const std::string& elementName) const;

        enums::ElementType GetElementType();

        std::vector<MMElement*> GetAllElements();
        std::vector<const MMElement*> GetAllElements() const;

        MMAttribute& GetAttribute(const std::string& attributeName);
        MMAttribute* FindAttribute(const std::string& attributeName);
        const MMAttribute* FindAttribute(const std::string& attributeName) const;
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
        std::vector<MMElement*> childOrder;
        std::map<std::string, MMAttribute> attributes;

        enums::ElementType elementType;
    };

} // types

#endif //XDFCREATOR_MMELEMENT_H
