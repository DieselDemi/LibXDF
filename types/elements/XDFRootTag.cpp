#include "../../include/elements/XDFRootTag.h"

#include <sstream>

namespace dd::libxdf::types::elements {
    XDFRootTag::XDFRootTag(ParsedTag) : MMElement("XDFFORMAT", enums::ElementType::GENERIC) {}

    XDFRootTag::XDFRootTag(float version)
    : MMElement("XDFFORMAT", enums::ElementType::GENERIC) {
        std::ostringstream value;
        value << version;
        AddAttribute({.name = "version", .value = value.str()});
    }
}
