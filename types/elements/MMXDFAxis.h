#ifndef XDFCREATOR_MMXDFAXIS_H
#define XDFCREATOR_MMXDFAXIS_H

#include "../MMElement.h"

namespace dd::libxdf::types::elements {

    class MMXDFAxis : public MMElement {
    public:
        explicit MMXDFAxis(char axisId = 'x');
    };

} // elements

#endif //XDFCREATOR_MMXDFAXIS_H
