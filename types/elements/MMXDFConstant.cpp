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
            MMElement("XDFCONSTANT",
                      {
                              {.name = "flags", .value = format("{:#x}", static_cast<int>(flags))}
                      }, true) {

        InsertElement(new MMElement("title", std::move(title)));
        InsertElement(new MMElement("description", std::move(description)));
        InsertElement(embeddedData);
        InsertElement(new MMElement("rangehigh", std::to_string(rangeHigh)));
        InsertElement(new MMElement("rangelow", std::to_string(rangeLow)));
        InsertElement(new MMElement("datatype", static_cast<uint32_t>(dataType)));
        InsertElement(new MMElement("unittype", static_cast<uint32_t>(unitType)));
        InsertElement(new MMElement("DALINK", {{.name="index", .value="0"}}));
        InsertElement(new MMMath(std::move(equation)));
    }

    MMXDFConstant::MMXDFConstant(MMEmbeddedData *embeddedData,
                                 std::string title,
                                 std::string description,
                                 float rangeHigh,
                                 float rangeLow,
                                 std::string equation,
                                 enums::ConstantFlags flags) :
    MMElement("XDFCONSTANT",
    {
        {.name = "flags", .value = format("{:#x}", static_cast<int>(flags))}
    }, true) {

        InsertElement(new MMElement("title", std::move(title)));
        InsertElement(new MMElement("description", std::move(description)));
        InsertElement(embeddedData);
        InsertElement(new MMElement("rangehigh", std::to_string(rangeHigh)));
        InsertElement(new MMElement("rangelow", std::to_string(rangeLow)));
        InsertElement(new MMElement("datatype", "0"));
        InsertElement(new MMElement("unittype", "0"));
        InsertElement(new MMElement("DALINK", {{.name="index", .value="0"}}));
        InsertElement(new MMMath(std::move(equation)));
    }

    MMXDFConstant::MMXDFConstant(MMEmbeddedData *embeddedData,
                                 std::string title,
                                 std::string description,
                                 float rangeHigh,
                                 float rangeLow,
                                 std::string equation) :
    MMElement("XDFCONSTANT", true)
    {
        InsertElement(new MMElement("title", std::move(title)));
        InsertElement(new MMElement("description", std::move(description)));
        InsertElement(embeddedData);
        InsertElement(new MMElement("rangehigh", std::to_string(rangeHigh)));
        InsertElement(new MMElement("rangelow", std::to_string(rangeLow)));
        InsertElement(new MMElement("datatype", "0x0"));
        InsertElement(new MMElement("unittype", "0x0"));
        InsertElement(new MMElement("DALINK", {{.name = "index", .value = "0"}}));
        InsertElement(new MMMath(std::move(equation)));

    }


}