#include "../../include/elements/MMXDFPatch.h"

namespace dd::libxdf::types::elements {

    MMXDFPatch::MMXDFPatch(
            std::string title,
            std::string description,
            std::initializer_list<MMXDFPatchEntry *> entries) :

            MMElement("XDFPATCH", enums::ElementType::PATCH, {}, true) {
        this->AddElement(new MMElement("title", enums::ElementType::GENERIC, std::move(title)));
        this->AddElement(new MMElement("description", enums::ElementType::GENERIC, std::move(description)));

        for (auto patchEntry: entries) {
            this->AddElement(static_cast<MMElement *>(patchEntry));
        }
    }
} // elements