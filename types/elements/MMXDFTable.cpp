#include "../../include/elements/MMXDFTable.h"

namespace dd::libxdf::types::elements {

    MMXDFTable::MMXDFTable(
            std::string title,
            std::string description,
            std::initializer_list<MMXDFAxis*> axis
    ) : MMElement("XDFTABLE", {}, true)
    {
        this->InsertElement(new MMElement("title", std::move(title)));
        this->InsertElement(new MMElement("description", std::move(description)));

        for(auto axi : axis) {
            this->InsertElement(static_cast<MMElement*>(axi));
        }
    }
}