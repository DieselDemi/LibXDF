#ifndef XDFCREATOR_MMXDFCHECKSUM_H
#define XDFCREATOR_MMXDFCHECKSUM_H

#include "../MMElement.h"
#include "../MMRegion.h"

namespace dd::libxdf::types::elements {
    class MMXDFChecksum final: public MMElement {
    public:
        explicit MMXDFChecksum(
                std::string title,
                uint32_t regionDataStart,
                uint32_t regionDataEnd,
                uint32_t storeAddress,
                CalculationMethod calculationMethod);
    };
}


#endif //XDFCREATOR_MMXDFCHECKSUM_H
