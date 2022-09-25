#include "MMRegion.h"
#include "../crossplatform/XdfStringFormat.h"
#include <utility>

//<REGION type="0xFFFFFFFF" startaddress="0x0" size="700000" regionflags="0x0" name="Binary File" desc="" />

namespace dd::libxdf::types {
    MMRegion::MMRegion(
            enums::RegionType type,
            uint32_t startAddress,
            uint32_t size,
            enums::RegionFlag flag,
            const std::string& regionName,
            const std::string& regionDescription)
    : MMElement("REGION",
    {
            {.name="type", .value = format("{:#x}", static_cast<uint64_t>(type))},
            {.name="startaddress", .value = format("{:#x}", startAddress)},
            {.name="size", .value = format("{:#x}", size)},
            {.name="regionflags", .value = format("{:#x}", static_cast<uint32_t>(flag))},
            {.name="name", .value = regionName},
            {.name="desc", .value = regionDescription}
    }, false) { /*Nothing to do here*/ }
} // types