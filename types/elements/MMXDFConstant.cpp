#include "../../include/elements/MMXDFConstant.h"
#include "../../include/MMMath.h"
#include "../../crossplatform/XdfStringFormat.h"

namespace dd::libxdf::types::elements {
    MMXDFConstant::MMXDFConstant(MMEmbeddedData *embeddedData,
                                 enums::DataType dataType,
                                 enums::UnitType unitType,
                                 std::string title,
                                 std::string description,
                                 float rangeHigh,
                                 float rangeLow,
                                 std::string equation,
                                 enums::ConstantFlags flags) :
            MMElement("XDFCONSTANT", enums::ElementType::CONSTANT,
                      {
                              {.name = "flags", .value = format("{:#x}", static_cast<int>(flags))}
                      }, true) {

        InsertElement(new MMElement("title", enums::ElementType::GENERIC, std::move(title)));
        InsertElement(new MMElement("description", enums::ElementType::GENERIC, std::move(description)));
        InsertElement(embeddedData);
        InsertElement(new MMElement("rangehigh", enums::ElementType::GENERIC, std::to_string(rangeHigh)));
        InsertElement(new MMElement("rangelow", enums::ElementType::GENERIC, std::to_string(rangeLow)));
        InsertElement(new MMElement("datatype", enums::ElementType::GENERIC, static_cast<uint32_t>(dataType)));
        InsertElement(new MMElement("unittype", enums::ElementType::GENERIC, static_cast<uint32_t>(unitType)));
        InsertElement(new MMElement("DALINK", enums::ElementType::GENERIC, {{.name="index", .value="0"}}));
        InsertElement(new MMMath(std::move(equation)));
    }

    MMXDFConstant::MMXDFConstant(MMEmbeddedData *embeddedData,
                                 std::string title,
                                 std::string description,
                                 float rangeHigh,
                                 float rangeLow,
                                 std::string equation,
                                 enums::ConstantFlags flags) :
    MMElement("XDFCONSTANT", enums::ElementType::CONSTANT,
    {
        {.name = "flags", .value = format("{:#x}", static_cast<int>(flags))}
    }, true) {

        InsertElement(new MMElement("title", enums::ElementType::GENERIC, std::move(title)));
        InsertElement(new MMElement("description", enums::ElementType::GENERIC, std::move(description)));
        InsertElement(embeddedData);
        InsertElement(new MMElement("rangehigh", enums::ElementType::GENERIC, std::to_string(rangeHigh)));
        InsertElement(new MMElement("rangelow", enums::ElementType::GENERIC, std::to_string(rangeLow)));
        InsertElement(new MMElement("datatype", enums::ElementType::GENERIC, "0"));
        InsertElement(new MMElement("unittype", enums::ElementType::GENERIC, "0"));
        InsertElement(new MMElement("DALINK", enums::ElementType::GENERIC, {{.name="index", .value="0"}}));
        InsertElement(new MMMath(std::move(equation)));
    }

    MMXDFConstant::MMXDFConstant(MMEmbeddedData *embeddedData,
                                 std::string title,
                                 std::string description,
                                 float rangeHigh,
                                 float rangeLow,
                                 std::string equation) :
    MMElement("XDFCONSTANT", enums::ElementType::GENERIC, true)
    {
        InsertElement(new MMElement("title", enums::ElementType::GENERIC, std::move(title)));
        InsertElement(new MMElement("description", enums::ElementType::GENERIC, std::move(description)));
        InsertElement(embeddedData);
        InsertElement(new MMElement("rangehigh", enums::ElementType::GENERIC, std::to_string(rangeHigh)));
        InsertElement(new MMElement("rangelow", enums::ElementType::GENERIC, std::to_string(rangeLow)));
        InsertElement(new MMElement("datatype", enums::ElementType::GENERIC, "0x0"));
        InsertElement(new MMElement("unittype", enums::ElementType::GENERIC, "0x0"));
        InsertElement(new MMElement("DALINK", enums::ElementType::GENERIC, {{.name = "index", .value = "0"}}));
        InsertElement(new MMMath(std::move(equation)));

    }


}