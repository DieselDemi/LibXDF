#include <format>
#include "MMEmbeddedData.h"

namespace dd::libxdf::types {
    MMEmbeddedData::MMEmbeddedData(uint32_t address, uint32_t elementSize, uint8_t majorStride, uint8_t minorStride) {
        this->name = "EMBEDDEDDATA";

        this->InsertAttribute({.name = "mmedaddress", .value = std::format("{:#x}", address)});
        this->InsertAttribute({.name = "mmedelementsizebits", .value = std::to_string(elementSize)});
        this->InsertAttribute({.name = "mmedmajorstridebits", .value = std::to_string(majorStride)});
        this->InsertAttribute({.name = "mmedminorstridebits", .value = std::to_string(minorStride)});
    }
} // types