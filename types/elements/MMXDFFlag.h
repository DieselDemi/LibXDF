#ifndef XDFCREATOR_MMXDFFLAG_H
#define XDFCREATOR_MMXDFFLAG_H

#include "../MMElement.h"
#include "../MMEmbeddedData.h"

namespace dd::libxdf::types::elements {

    class MMXDFFlag : public MMElement {
    public:
        explicit MMXDFFlag(MMEmbeddedData *embeddedData, std::string title, std::string description, uint8_t maskValue);
    };

} // elements

#endif //XDFCREATOR_MMXDFFLAG_H
