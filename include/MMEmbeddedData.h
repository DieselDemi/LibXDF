#ifndef XDFCREATOR_MMEMBEDDEDDATA_H
#define XDFCREATOR_MMEMBEDDEDDATA_H

#include <optional>

#include "MMElement.h"

namespace dd::libxdf::types {
    class MMEmbeddedData : public MMElement {
    public:
        explicit MMEmbeddedData(ParsedTag);
        explicit MMEmbeddedData(uint32_t address, uint32_t elementSize = 32, uint8_t majorStride = 0, uint8_t minorStride = 0);
        explicit MMEmbeddedData(
                std::optional<uint64_t> address,
                uint32_t elementSize,
                int64_t majorStride,
                int64_t minorStride,
                std::optional<uint64_t> typeFlags,
                std::optional<uint32_t> rowCount,
                std::optional<uint32_t> columnCount);

        [[nodiscard]] std::optional<uint64_t> GetAddress() const;
        [[nodiscard]] std::optional<uint32_t> GetElementSizeBits() const;
        [[nodiscard]] std::optional<int64_t> GetMajorStrideBits() const;
        [[nodiscard]] std::optional<int64_t> GetMinorStrideBits() const;
        [[nodiscard]] std::optional<uint32_t> GetRowCount() const;
        [[nodiscard]] std::optional<uint32_t> GetColumnCount() const;
        [[nodiscard]] std::optional<uint64_t> GetTypeFlags() const;
    };

} // types

#endif //XDFCREATOR_MMEMBEDDEDDATA_H
