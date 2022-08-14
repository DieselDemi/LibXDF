#include "MMXDFAxis.h"
#include "../MMEmbeddedData.h"
#include "../MMMath.h"

namespace dd::libxdf::types::elements {

    MMXDFAxis::MMXDFAxis(const std::string& axisId,
                         std::string equation,
                         uint32_t indexCountValue,
                         uint8_t dataTypeValue,
                         uint8_t unitTypeValue,
                         uint8_t decimalPlaceValue,
                         double minValue,
                         double maxValue,
                         uint8_t outputTypeValue) :
            MMElement("XDFAXIS", {
                              {.name="id", .value=axisId}
                      }, true
            ) {

        auto *embeddedData = new MMEmbeddedData(0);

        if (axisId == "X" || axisId == "Y") {
            this->InsertElement(new MMElement("indexcount", std::to_string(indexCountValue)));
            this->InsertElement(new MMElement("datatype", std::to_string(dataTypeValue)));
            this->InsertElement(new MMElement("unittype", std::to_string(unitTypeValue)));
            this->InsertElement(new MMElement("DALINK", {{.name="index", .value="0"}}));
            this->InsertElement(new MMElement("LABEL", {{.name="index", .value="0"}, {.name="value", .value="0.00"}}));
        } else if (axisId == "Z") {
            this->InsertElement(new MMElement("decimalpl", std::to_string(decimalPlaceValue)));
            this->InsertElement(new MMElement("min", std::to_string(minValue)));
            this->InsertElement(new MMElement("max", std::to_string(maxValue)));
            this->InsertElement(new MMElement("outputtype", std::to_string(outputTypeValue)));
        } // Else don't add any elements, this is an error

        auto *mathElement = new MMMath(std::move(equation));

        this->InsertElement(embeddedData);
        this->InsertElement(mathElement);
    }
} // elements