#include "MMXDFConstant.h"
#include "../MMMath.h"
#include "../../crossplatform/XdfStringFormat.h"

namespace dd::libxdf::types::elements {
    MMXDFConstant::MMXDFConstant(MMEmbeddedData *embeddedData, std::string title, std::string description, float rangeHigh, float rangeLow, enums::ConstantFlags flags) :
            MMElement("XDFCONSTANT",
                      {
                              {.name = "flags", .value = format("{:#x}",static_cast<int>(flags))}
                      }, true
            )
    {

        InsertElement(new MMElement("title", std::move(title)));
        InsertElement(new MMElement("description", std::move(description)));
        InsertElement(embeddedData);
        InsertElement(new MMElement("rangehigh", std::to_string(rangeHigh)));
        InsertElement(new MMElement("rangelow", std::to_string(rangeLow)));
        InsertElement(new MMElement("datatype", "0")); //TODO Datatype value
        InsertElement(new MMElement("unittype", "0")); //TODO Unittype value
        InsertElement(new MMElement("DALINK", {{.name="index", .value="0"}}));
        InsertElement(new MMMath("X")); //TODO Equations
    }
}