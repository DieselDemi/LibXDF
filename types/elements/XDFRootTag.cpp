#include "XDFRootTag.h"

namespace dd::libxdf::types::elements {

    XDFRootTag::XDFRootTag() {
        this->name = "XDFFORMAT";

        MMAttribute versionAttribute = {
                .name = "version",
                .value = "1.70"
        };

        this->InsertAttribute(versionAttribute);
    }
}