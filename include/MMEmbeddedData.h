#ifndef XDFCREATOR_MMEMBEDDEDDATA_H
#define XDFCREATOR_MMEMBEDDEDDATA_H

#include "MMElement.h"

namespace dd::libxdf::types {
    class MMEmbeddedData : public MMElement {
    public:
        explicit MMEmbeddedData(uint32_t address, uint32_t elementSize = 32, uint8_t majorStride = 0, uint8_t minorStride = 0);
    };

} // types

#endif //XDFCREATOR_MMEMBEDDEDDATA_H
