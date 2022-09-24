#ifndef LIBXDF_MMREGION_H
#define LIBXDF_MMREGION_H

#include <cstdint>
#include "MMElement.h"

namespace dd::libxdf::types {
    enum class CalculationMethod {
        //TODO: Fill out all the calculating methods
        UNKNOWN = 0
    };

    enum class RegionType: uint64_t {
        //TODO: All the region types
        DEFAULT = 0xFFFFFFFF
    };

    enum class RegionFlag: uint32_t {
        DEFAULT = 0x0
    };

    class MMRegion: public MMElement {
    public:
        explicit MMRegion(RegionType type, uint32_t startAddress, uint32_t size, RegionFlag flag, const std::string& regionName, const std::string& regionDescription);
    };

} // types

#endif //LIBXDF_MMREGION_H
