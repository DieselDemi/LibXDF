#ifndef XDFCREATOR_MMXDFHEADER_H
#define XDFCREATOR_MMXDFHEADER_H

#include "../MMElement.h"
#include "../MMCategory.h"
#include "../MMTypes.h"

namespace dd::libxdf::types::elements {
    class MMXDFHeader : public MMElement {
    public:
        explicit MMXDFHeader(
                enums::HeaderFlags flags,
                float fileVersion,
                std::string title,
                std::string description,
                std::string author,
                uint32_t offset,
                uint32_t offsetSubtract,
                std::initializer_list<MMCategory*> categories);
        std::string ToString() override;
    };

} // elements

#endif //XDFCREATOR_MMXDFHEADER_H
