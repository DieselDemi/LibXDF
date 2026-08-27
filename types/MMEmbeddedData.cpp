#include "../include/MMEmbeddedData.h"
#include "../crossplatform/XdfStringFormat.h"

#include <charconv>
#include <string_view>

namespace dd::libxdf::types {
    namespace {
        template<typename T>
        std::optional<T> ParseInteger(const MMAttribute* attribute, int base) {
            if (attribute == nullptr) return std::nullopt;

            std::string_view value = attribute->value;
            if (base == 16 && value.size() > 2 && value[0] == '0' && (value[1] == 'x' || value[1] == 'X')) {
                value.remove_prefix(2);
            }

            T result{};
            const auto parsed = std::from_chars(value.data(), value.data() + value.size(), result, base);
            if (parsed.ec != std::errc{} || parsed.ptr != value.data() + value.size()) return std::nullopt;
            return result;
        }
    }

    MMEmbeddedData::MMEmbeddedData(ParsedTag) : MMElement("EMBEDDEDDATA", enums::ElementType::EMBEDDED_DATA) {}

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

    MMEmbeddedData::MMEmbeddedData(
            std::optional<uint64_t> address,
            uint32_t elementSize,
            int64_t majorStride,
            int64_t minorStride,
            std::optional<uint64_t> typeFlags,
            std::optional<uint32_t> rowCount,
            std::optional<uint32_t> columnCount)
            : MMElement("EMBEDDEDDATA", enums::ElementType::EMBEDDED_DATA) {
        if (typeFlags) AddAttribute({.name="mmedtypeflags", .value=NumToHex(*typeFlags)});
        if (address) AddAttribute({.name="mmedaddress", .value=NumToHex(*address)});
        AddAttribute({.name="mmedelementsizebits", .value=std::to_string(elementSize)});
        if (rowCount) AddAttribute({.name="mmedrowcount", .value=std::to_string(*rowCount)});
        if (columnCount) AddAttribute({.name="mmedcolcount", .value=std::to_string(*columnCount)});
        AddAttribute({.name="mmedmajorstridebits", .value=std::to_string(majorStride)});
        AddAttribute({.name="mmedminorstridebits", .value=std::to_string(minorStride)});
    }

    std::optional<uint64_t> MMEmbeddedData::GetAddress() const {
        return ParseInteger<uint64_t>(FindAttribute("mmedaddress"), 16);
    }

    std::optional<uint32_t> MMEmbeddedData::GetElementSizeBits() const {
        return ParseInteger<uint32_t>(FindAttribute("mmedelementsizebits"), 10);
    }

    std::optional<int64_t> MMEmbeddedData::GetMajorStrideBits() const {
        return ParseInteger<int64_t>(FindAttribute("mmedmajorstridebits"), 10);
    }

    std::optional<int64_t> MMEmbeddedData::GetMinorStrideBits() const {
        return ParseInteger<int64_t>(FindAttribute("mmedminorstridebits"), 10);
    }

    std::optional<uint32_t> MMEmbeddedData::GetRowCount() const {
        return ParseInteger<uint32_t>(FindAttribute("mmedrowcount"), 10);
    }

    std::optional<uint32_t> MMEmbeddedData::GetColumnCount() const {
        return ParseInteger<uint32_t>(FindAttribute("mmedcolcount"), 10);
    }

    std::optional<uint64_t> MMEmbeddedData::GetTypeFlags() const {
        return ParseInteger<uint64_t>(FindAttribute("mmedtypeflags"), 16);
    }
} // types
