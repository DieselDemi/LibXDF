#include "MMXDFPatch.h"

namespace dd::libxdf::types::elements {

    MMXDFPatch::MMXDFPatch(
            std::string title,
            std::string description,
            std::initializer_list<MMXDFPatchEntry *> entries) :

            MMElement("XDFPATCH", {}, true) {
        this->AddElement(new MMElement("title", std::move(title)));
        this->AddElement(new MMElement("description", std::move(description)));

        for (auto patchEntry: entries) {
            this->AddElement(static_cast<MMElement *>(patchEntry));
        }
    }
} // elements