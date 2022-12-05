#include "../include/MMCategory.h"

namespace dd::libxdf::types {
    MMCategory::MMCategory(std::string name, uint16_t index) : MMElement("CATEGORY", {
            {.name="index", .value=std::to_string(index)},
            {.name="name", .value=std::move(name)}
    }), index(index) {

    }
} // types