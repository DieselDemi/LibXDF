#include <format>
#include "MMEmbeddedData.h"

namespace dd::libxdf::types {
    MMEmbeddedData::MMEmbeddedData(
            uint32_t address,
            uint32_t elementSize,
            uint8_t majorStride,
            uint8_t minorStride
    ) : MMElement("EMBEDDEDDATA", {
            {.name = "mmedaddress", .value = std::format("{:#x}", address)},
            {.name = "mmedelementsizebits", .value = std::to_string(elementSize)},
            {.name = "mmedmajorstridebits", .value = std::to_string(majorStride)},
            {.name = "mmedminorstridebits", .value = std::to_string(minorStride)}
    }) { /**Nothing to do here**/ }
} // types