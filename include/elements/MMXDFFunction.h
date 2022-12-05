#ifndef XDFCREATOR_MMXDFFUNCTION_H
#define XDFCREATOR_MMXDFFUNCTION_H

#include "../MMElement.h"
#include "MMXDFAxis.h"

namespace dd::libxdf::types::elements {

    class MMXDFFunction : public MMElement {
    public:
        explicit MMXDFFunction(std::string title, std::string description, std::initializer_list<MMXDFAxis*> axis);
    };

} // elements

#endif //XDFCREATOR_MMXDFFUNCTION_H
