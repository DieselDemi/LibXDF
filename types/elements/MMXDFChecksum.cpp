#include "MMXDFChecksum.h"

namespace dd::libxdf::types::elements {
    MMXDFChecksum::MMXDFChecksum() {
        this->name = "XDFCHECKSUM";

        auto* titleElement = new MMElement();
        titleElement->SetName("title");
        titleElement->SetText("TODO - Title");

        auto* regionElement = new MMElement();
        regionElement->SetName("REGION");

        auto* regionDataStartElement = new MMElement();
        regionDataStartElement->SetName("datastart");
        regionDataStartElement->SetText("TODO - region data start");

        auto* regionDataEndElement = new MMElement();
        regionDataEndElement->SetName("dataend");
        regionDataEndElement->SetText("TODO - Region data end");

        auto* regionStoreAddressElement = new MMElement();
        regionStoreAddressElement->SetName("storeaddress");
        regionStoreAddressElement->SetText("TODO - Region store address");

        auto* regionCalculationMethodElement = new MMElement();
        regionCalculationMethodElement->SetName("calculationmethod");
        regionCalculationMethodElement->SetText("TODO - calculation method");

        regionElement->AddElement(regionDataStartElement);
        regionElement->AddElement(regionDataEndElement);
        regionElement->AddElement(regionStoreAddressElement);
        regionElement->AddElement(regionCalculationMethodElement);

        this->InsertElement(titleElement);
        this->InsertElement(regionElement);
    }
}
