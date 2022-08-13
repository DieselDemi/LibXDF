#include "MMXDFFlag.h"
#include "../MMEmbeddedData.h"

namespace dd::libxdf::types::elements {
    MMXDFFlag::MMXDFFlag() {
        this->name = "XDFFLAG";
        this->InsertAttribute({.name = "uniqueid", .value = this->GetUniqueHexId()});

        auto* titleElement = new MMElement();
        titleElement->SetName("title");
        titleElement->SetText("TODO - Title Text");

        auto* descriptionElement = new MMElement();
        descriptionElement->SetName("description");
        descriptionElement->SetText("TODO - description");

        //TODO - Move these to their own type
        auto *embeddedDataElement = new MMEmbeddedData(0);

        auto* maskElement = new MMElement();
        maskElement->SetName("mask");
        maskElement->SetText("TODO - mask data");

        this->InsertElement(titleElement);
        this->InsertElement(descriptionElement);
        this->InsertElement(embeddedDataElement);
        this->InsertElement(maskElement);
    }
} // elements