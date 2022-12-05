#include "../../include/elements/XDFRootTag.h"

namespace dd::libxdf::types::elements {

    XDFRootTag::XDFRootTag(float version)
    : MMElement("XDFFORMAT", {{.name = "version",.value = std::to_string(version)}}) {/* Nothing to do here */}
}