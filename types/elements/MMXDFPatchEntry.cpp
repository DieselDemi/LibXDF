#include "../../include/elements/MMXDFPatchEntry.h"
#include "../../crossplatform/XdfStringFormat.h"

namespace dd::libxdf::types::elements {
    MMXDFPatchEntry::MMXDFPatchEntry(std::string name, uint32_t address, uint32_t datasize, std::string patchData) : MMElement("XDFPATCHENTRY", {
        {.name="name", .value=std::move(name)},
        {.name="address", .value=format("{#:x}", address)},
        {.name="datasize", .value=format("{#:x}", datasize)},
        {.name="patchdata", .value=std::move(patchData)}
    }) {/* Nothing to do here*/}
} // elements