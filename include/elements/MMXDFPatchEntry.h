
#ifndef XDFCREATOR_MMXDFPATCHENTRY_H
#define XDFCREATOR_MMXDFPATCHENTRY_H

#include "../MMElement.h"

namespace dd::libxdf::types::elements {

    class MMXDFPatchEntry final : public MMElement {
    public:
        MMXDFPatchEntry(std::string name, uint32_t address, uint32_t datasize, std::string patchData);
    };

} // elements

#endif //XDFCREATOR_MMXDFPATCHENTRY_H
