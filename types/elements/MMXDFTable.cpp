#include "../../include/elements/MMXDFTable.h"

namespace dd::libxdf::types::elements {

    MMXDFTable::MMXDFTable(
            std::string title,
            std::string description,
            std::initializer_list<MMXDFAxis*> axis
    ) : MMElement("XDFTABLE", enums::ElementType::TABLE, {}, true)
    {
        this->InsertElement(new MMElement("title", enums::ElementType::GENERIC, std::move(title)));
        this->InsertElement(new MMElement("description", enums::ElementType::GENERIC, std::move(description)));

        for(auto axi : axis) {
            this->InsertElement(static_cast<MMElement*>(axi));
        }
    }

    MMXDFTable::MMXDFTable(
            std::string title,
            std::string description,
            const std::vector<MMXDFAxis*>& axis
    ) : MMElement("XDFTABLE", enums::ElementType::TABLE, {}, true)
    {
        this->InsertElement(new MMElement("title", enums::ElementType::GENERIC, std::move(title)));
        this->InsertElement(new MMElement("description", enums::ElementType::GENERIC, std::move(description)));

        for(auto axi : axis) {
            this->InsertElement(static_cast<MMElement*>(axi));
        }
    }
}