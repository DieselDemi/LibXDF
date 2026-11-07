#include "../include/MMCategory.h"

#include <charconv>
#include <string_view>

namespace dd::libxdf::types {
    MMCategory::MMCategory(ParsedTag) : MMElement("CATEGORY", enums::ElementType::CATEGORY), index(0) {}

    MMCategory::MMCategory(std::string name, uint16_t index) : MMElement("CATEGORY", enums::ElementType::CATEGORY, {
            {.name="index", .value=std::to_string(index)},
            {.name="name", .value=std::move(name)}
    }), index(index) {

    }

    uint32_t MMCategory::GetIndex() const {
        const auto* attribute = FindAttribute("index");
        if (attribute == nullptr) return index;
        std::string_view value = attribute->value;
        int base = 10;
        if (value.starts_with("0x") || value.starts_with("0X")) {
            value.remove_prefix(2);
            base = 16;
        }
        uint32_t result{};
        const auto parsed = std::from_chars(value.data(), value.data() + value.size(), result, base);
        return parsed.ec == std::errc{} && parsed.ptr == value.data() + value.size() ? result : index;
    }
} // types
