#ifndef XDFCREATOR_MMXDFCONSTANT_H
#define XDFCREATOR_MMXDFCONSTANT_H

#include "../MMElement.h"
#include "../MMEmbeddedData.h"
#include "../MMTypes.h"

namespace dd::libxdf::types::elements {
    class MMXDFConstant final : public MMElement {
    public:
        explicit MMXDFConstant(
                MMEmbeddedData *embeddedData,
                enums::DataType dataType,
                enums::UnitType unitType,
                std::string title,
                std::string description,
                float rangeHigh,
                float rangeLow,
                std::string equation,
                enums::ConstantFlags flags);

        explicit MMXDFConstant(
                MMEmbeddedData *embeddedData,
                std::string title,
                std::string description,
                float rangeHigh,
                float rangeLow,
                std::string equation,
                enums::ConstantFlags flags);

        explicit MMXDFConstant(
                MMEmbeddedData *embeddedData,
                std::string title,
                std::string description,
                float rangeHigh,
                float rangeLow,
                std::string equation);

    };
}


#endif //XDFCREATOR_MMXDFCONSTANT_H
