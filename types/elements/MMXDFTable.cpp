#include "MMXDFTable.h"

namespace dd::libxdf::types::elements {

    MMXDFTable::MMXDFTable(std::string title, std::string description, std::initializer_list<MMXDFAxis*> axis) {
        this->name = "XDFTABLE";
        InsertAttribute({.name = "uniqueid", .value = this->GetUniqueHexId()});

        auto* titleElement = new MMElement();
        titleElement->SetName("title");
        titleElement->SetText(title);

        auto* descriptionElement = new MMElement();
        descriptionElement->SetName("description");
        descriptionElement->SetText(description);

        this->InsertElement(titleElement);
        this->InsertElement(descriptionElement);

        for(auto axi : axis) {
            this->InsertElement((MMElement *) axi);
        }
    }
} // elements