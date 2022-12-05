#ifndef XDFCREATOR_MMDEFAULTSELEMENT_H
#define XDFCREATOR_MMDEFAULTSELEMENT_H

#include "MMElement.h"

namespace dd::libxdf::types {

    class MMDefaultsElement : public MMElement {
    public:
        explicit MMDefaultsElement(
                uint32_t dataSizeInBits = 8,
                uint8_t sigDigits = 2,
                uint8_t outputType = 1,
                uint8_t signedValue = 0,
                uint8_t lsbFirst = 0,
                uint8_t floatValue = 0);
    };

} // types

#endif //XDFCREATOR_MMDEFAULTSELEMENT_H
