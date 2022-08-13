#ifndef XDFCREATOR_MMMATHELEMENT_H
#define XDFCREATOR_MMMATHELEMENT_H

#include "MMElement.h"

namespace dd::libxdf::types {

    class MMMathElement : public MMElement {
    public:
        explicit MMMathElement(std::string equation);
    };

} // types

#endif //XDFCREATOR_MMMATHELEMENT_H
