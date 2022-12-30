#include "../../include/elements/MMXDFAxis.h"
#include "../../include/MMEmbeddedData.h"
#include "../../include/MMMath.h"

namespace dd::libxdf::types::elements {

    MMXDFAxis::MMXDFAxis(
            MMEmbeddedData* embeddedData,
            const std::string& axisId,
            std::string equation,
            uint32_t indexCountValue,
            uint8_t dataTypeValue,
            uint8_t unitTypeValue,
            uint8_t decimalPlaceValue,
            double minValue,
            double maxValue,
            uint8_t outputTypeValue) :
            MMElement("XDFAXIS", enums::ElementType::AXIS, {
                              {.name="id", .value=axisId}
                      }, true
            ) {

//        auto *embeddedData = new MMEmbeddedData(0);

        if (axisId == "X" || axisId == "Y") {
            this->InsertElement(new MMElement("indexcount", enums::ElementType::GENERIC, std::to_string(indexCountValue)));
            this->InsertElement(new MMElement("datatype", enums::ElementType::GENERIC, std::to_string(dataTypeValue)));
            this->InsertElement(new MMElement("unittype", enums::ElementType::GENERIC, std::to_string(unitTypeValue)));
            this->InsertElement(new MMElement("DALINK", enums::ElementType::GENERIC, {{.name="index", .value="0"}}));
            this->InsertElement(new MMElement("LABEL", enums::ElementType::GENERIC, {{.name="index", .value="0"}, {.name="value", .value="0.00"}}));
        } else if (axisId == "Z") {
            this->InsertElement(new MMElement("decimalpl", enums::ElementType::GENERIC, std::to_string(decimalPlaceValue)));
            this->InsertElement(new MMElement("min", enums::ElementType::GENERIC, std::to_string(minValue)));
            this->InsertElement(new MMElement("max", enums::ElementType::GENERIC, std::to_string(maxValue)));
            this->InsertElement(new MMElement("outputtype", enums::ElementType::GENERIC, std::to_string(outputTypeValue)));
        } // Else don't add any elements, this is an error

        auto *mathElement = new MMMath(std::move(equation));

        this->InsertElement(embeddedData);
        this->InsertElement(mathElement);
    }
} // elements