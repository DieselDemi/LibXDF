#ifndef XDFCREATOR_MMXDFCHECKSUM_H
#define XDFCREATOR_MMXDFCHECKSUM_H

#include "../MMElement.h"

namespace dd::libxdf::types::elements {
    class MMXDFChecksum : public MMElement {
    public:
        explicit MMXDFChecksum(
                std::string title,
                uint32_t regionDataStart,
                uint32_t regionDataEnd,
                uint32_t storeAddress,
                uint32_t calculationMethod);
    };
}


#endif //XDFCREATOR_MMXDFCHECKSUM_H
