#ifndef XDFCREATOR_MMXDFFLAG_H
#define XDFCREATOR_MMXDFFLAG_H

#include "../MMElement.h"
#include "../MMEmbeddedData.h"
#include <optional>

namespace dd::libxdf::types::elements {

    class MMXDFFlag : public MMElement {
    public:
        explicit MMXDFFlag(ParsedTag);
        explicit MMXDFFlag(MMEmbeddedData *embeddedData, std::string title, std::string description, uint8_t maskValue);
        [[nodiscard]] MMEmbeddedData* GetEmbeddedData();
        [[nodiscard]] std::optional<uint64_t> GetMask() const;
    };

} // elements

#endif //XDFCREATOR_MMXDFFLAG_H
