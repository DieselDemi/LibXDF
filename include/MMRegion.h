#ifndef LIBXDF_MMREGION_H
#define LIBXDF_MMREGION_H

#include <cstdint>
#include "MMElement.h"
#include "MMTypes.h"

namespace dd::libxdf::types {

    class MMRegion: public MMElement {
    public:
        explicit MMRegion(enums::RegionType type, uint32_t startAddress, uint32_t size, enums::RegionFlag flag, const std::string& regionName, const std::string& regionDescription);
        explicit MMRegion(uint32_t startAddress, uint32_t endAddress, uint32_t storeAddress, enums::CalculationMethod calculationMethod);
    };

} // types

#endif //LIBXDF_MMREGION_H
