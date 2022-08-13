#ifndef XDFCREATOR_MMXDFHEADER_H
#define XDFCREATOR_MMXDFHEADER_H

#include "../MMElement.h"

namespace dd::libxdf::types::elements {
    class MMXDFHeader : public MMElement {
    public:
        explicit MMXDFHeader();
        std::string ToString() override;
    };

} // elements

#endif //XDFCREATOR_MMXDFHEADER_H
