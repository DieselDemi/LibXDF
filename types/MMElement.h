#ifndef XDFCREATOR_MMELEMENT_H
#define XDFCREATOR_MMELEMENT_H

#include <cstdlib>
#include <map>
#include <string>
#include <vector>

#include "MMAttribute.h"

namespace dd::libxdf::types {
    class MMElement {
    public:
        explicit MMElement(std::string name, std::string textValue = "", bool displayUID = false);
        MMElement(std::string name, std::initializer_list<MMAttribute> attributes, bool displayUID = false);
        ~MMElement();

        void SetUniqueId(uint64_t id);
        void SetName(const std::string& newName);
        void SetText(const std::string& newText);

        void AddElement(MMElement*);
        void AddAttribute(const MMAttribute&);

        MMElement& GetElement(const std::string&);
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
    };

} // types

#endif //XDFCREATOR_MMELEMENT_H
