#ifndef XDFCREATOR_MMXDFPATCH_H
#define XDFCREATOR_MMXDFPATCH_H

#include "../MMElement.h"
#include "MMXDFPatchEntry.h"

namespace dd::libxdf::types::elements {
    class MMXDFPatch final : public MMElement {
    public:
        MMXDFPatch(std::string title, std::string description, std::initializer_list<MMXDFPatchEntry*> entries);
    };
} // elements

#endif //XDFCREATOR_MMXDFPATCH_H
