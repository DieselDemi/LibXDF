#include "XDFRootTag.h"
#include "MMXDFHeader.h"
#include "MMXDFChecksum.h"

namespace dd::libxdf::types::elements {

    XDFRootTag::XDFRootTag() {
        this->name = "XDFFORMAT";


        this->InsertAttribute({.name = "version",.value = "1.70"});
    }
}