#ifndef XDFCREATOR_MMXDFCONSTANT_H
#define XDFCREATOR_MMXDFCONSTANT_H

#include "../MMElement.h"
#include "../MMXDFConstantFlags.h"

namespace dd::libxdf::types::elements {
    class MMXDFConstant : public MMElement {
    public:
        explicit MMXDFConstant(std::string title, std::string description, flags::MMXDFConstantFlags flags);
    };
}


#endif //XDFCREATOR_MMXDFCONSTANT_H
