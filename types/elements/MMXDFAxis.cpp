#include "MMXDFAxis.h"
#include "../MMEmbeddedData.h"
#include "../MMMathElement.h"

namespace dd::libxdf::types::elements {

    MMXDFAxis::MMXDFAxis(char axisId) {
        this->name = "XDFAXIS";

        this->InsertAttribute({.name="id", .value=std::to_string(axisId)});
        InsertAttribute({.name = "uniqueid", .value = this->GetUniqueHexId()});

        auto *embeddedData = new MMEmbeddedData(0);

        if (axisId == 'x' || axisId == 'y') {
            //Index count
            auto *indexCountElement = new MMElement();
            indexCountElement->SetName("indexcount");
            indexCountElement->SetText("TODO - Index Count");

            auto *dataTypeElement = new MMElement();
            dataTypeElement->SetName("datatype");
            dataTypeElement->SetText("TODO - Data type value");

            auto *unitTypeElement = new MMElement();
            unitTypeElement->SetName("unittype");
            unitTypeElement->SetText("TODO - Unit type");

            auto *daLinkElement = new MMElement();
            daLinkElement->SetName("DALINK");
            daLinkElement->AddAttribute({.name="index", .value="0"});

            auto *labelElement = new MMElement();
            labelElement->SetName("LABEL");
            labelElement->AddAttribute({.name="index", .value="0"});
            labelElement->AddAttribute({.name="value", .value="0.00"});

            this->InsertElement(indexCountElement);
            this->InsertElement(dataTypeElement);
            this->InsertElement(unitTypeElement);
            this->InsertElement(daLinkElement);
            this->InsertElement(labelElement);

        } else {
            auto *decimalPlaceElement = new MMElement();
            decimalPlaceElement->SetName("decimalpl");
            decimalPlaceElement->SetText("TODO - Decimal places");

            auto *minElement = new MMElement();
            minElement->SetName("min");
            minElement->SetText("TODO - minimum");

            auto *maxElement = new MMElement();
            maxElement->SetName("max");
            maxElement->SetText("TODO - maximum");

            auto *outputTypeElement = new MMElement();
            outputTypeElement->SetName("outputtype");
            outputTypeElement->SetText("TODO - Output type value");

            this->InsertElement(decimalPlaceElement);
            this->InsertElement(minElement);
            this->InsertElement(maxElement);
            this->InsertElement(outputTypeElement);
        }

        auto *mathElement = new MMMathElement("X");

        this->InsertElement(embeddedData);
        this->InsertElement(mathElement);
    }
} // elements