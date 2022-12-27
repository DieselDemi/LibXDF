#include "../../include/elements/MMXDFChecksum.h"
#include "../../crossplatform/XdfStringFormat.h"

namespace dd::libxdf::types::elements {
    MMXDFChecksum::MMXDFChecksum(std::string title,
                                 uint32_t regionDataStart,
                                 uint32_t regionDataEnd,
                                 uint32_t storeAddress,
                                 enums::CalculationMethod calculationMethod) : MMElement("XDFCHECKSUM", true) {

        auto *titleElement = new MMElement("title", std::move(title));
        auto *regionElement = new MMRegion(regionDataStart, regionDataEnd, storeAddress, calculationMethod);

        this->InsertElement(titleElement);
        this->InsertElement(regionElement);
    }
}
