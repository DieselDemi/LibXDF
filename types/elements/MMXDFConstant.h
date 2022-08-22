#ifndef XDFCREATOR_MMXDFCONSTANT_H
#define XDFCREATOR_MMXDFCONSTANT_H

#include "../MMElement.h"
#include "../MMEmbeddedData.h"
#include "../XDFConstantFlags.h"

namespace dd::libxdf::types::elements {
    class MMXDFConstant : public MMElement {
    public:
        explicit MMXDFConstant(
                MMEmbeddedData *embeddedData,
                std::string title,
                std::string description,
                float rangeHigh,
                float rangeLow,
                flags::XDFConstantFlags flags);
    };
}


#endif //XDFCREATOR_MMXDFCONSTANT_H
