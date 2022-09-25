#ifndef LIBXDF_MMTYPES_H
#define LIBXDF_MMTYPES_H

#include <cstdint>

namespace dd::libxdf::types::enums {
    enum class HeaderFlags {
        UNKNOWN = 0x1
    };

    enum class ConstantFlags {
        FIRST = 0xc,
        SECOND = 0xd
    };

    enum class DataType: uint8_t {
        //TODO: All the data types
        NONE = 0x0
    };

    enum class UnitType: uint8_t {
        //TODO: All the unit types
        NONE = 0x0
    };

    enum class CalculationMethod {
        //TODO: Fill out all the calculating methods
        UNKNOWN = 0
    };

    enum class RegionType: uint64_t {
        //TODO: All the region types
        DEFAULT = 0xFFFFFFFF
    };

    enum class RegionFlag: uint32_t {
        //TODO: All the region flags
        DEFAULT = 0x0
    };
} // types

#endif //LIBXDF_MMTYPES_H
