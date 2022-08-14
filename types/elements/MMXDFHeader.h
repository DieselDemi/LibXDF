#ifndef XDFCREATOR_MMXDFHEADER_H
#define XDFCREATOR_MMXDFHEADER_H

#include "../MMElement.h"
#include "../MMCategory.h"

namespace dd::libxdf::types::elements {
    enum class XDFHeaderFlags {
        UNKNOWN = 0x1
    };

    class MMXDFHeader : public MMElement {
    public:
        explicit MMXDFHeader(
                XDFHeaderFlags flags,
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
