#include "../include/MMEmbeddedData.h"
#include "../crossplatform/XdfStringFormat.h"

namespace dd::libxdf::types {
    MMEmbeddedData::MMEmbeddedData(
            uint32_t address,
            uint32_t elementSize,
            uint8_t majorStride,
            uint8_t minorStride
    ) : MMElement("EMBEDDEDDATA", enums::ElementType::EMBEDDED_DATA, {
            {.name = "mmedaddress", .value = format("{:#x}", address)},
            {.name = "mmedelementsizebits", .value = std::to_string(elementSize)},
            {.name = "mmedmajorstridebits", .value = std::to_string(majorStride)},
            {.name = "mmedminorstridebits", .value = std::to_string(minorStride)}
    }) { /**Nothing to do here**/ }
} // types