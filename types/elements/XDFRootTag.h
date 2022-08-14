#ifndef XDFCREATOR_XDFROOTTAG_H
#define XDFCREATOR_XDFROOTTAG_H

#include "../MMElement.h"

namespace dd::libxdf::types::elements {
    class XDFRootTag : public MMElement {
    public:
        explicit XDFRootTag(float version = 1.7f);
    };
}


#endif //XDFCREATOR_XDFROOTTAG_H
