#include "MMXDFChecksum.h"

#include <format>

namespace dd::libxdf::types::elements {
    MMXDFChecksum::MMXDFChecksum(std::string title,
                                 uint32_t regionDataStart,
                                 uint32_t regionDataEnd,
                                 uint32_t storeAddress,
                                 uint32_t calculationMethod) : MMElement("XDFCHECKSUM") {

        auto *titleElement = new MMElement("title", std::move(title));

        //TODO Move this to its own class
        auto *regionElement = new MMElement("REGION");
        regionElement->AddElement(new MMElement("datastart", std::format("{:#x}", regionDataStart)));
        regionElement->AddElement(new MMElement("dataend", std::format("{:#x}", regionDataEnd)));
        regionElement->AddElement(new MMElement("storeaddress", std::format("{:#x}", storeAddress)));
        regionElement->AddElement(new MMElement("calculationmethod", std::format("{:#x}", calculationMethod)));

        this->InsertElement(titleElement);
        this->InsertElement(regionElement);
    }
}
