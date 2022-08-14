#ifndef XDFCREATOR_MMXDFAXIS_H
#define XDFCREATOR_MMXDFAXIS_H

#include "../MMElement.h"

namespace dd::libxdf::types::elements {

    class MMXDFAxis : public MMElement {
    public:
        explicit MMXDFAxis(
                char axisId = 'x',
                std::string equation = "X",
                uint32_t indexCountValue = 1,
                uint8_t dataTypeValue = 0,
                uint8_t unitTypeValue = 0,
                uint8_t decimalPlaceValue = 2,
                double minValue = 0.00,
                double maxValue = 255.00,
                uint8_t outputTypeValue = 1
                        );
    };

} // elements

#endif //XDFCREATOR_MMXDFAXIS_H
