#include "MMXDFFlag.h"
#include "../MMEmbeddedData.h"
#include "../../crossplatform/XdfStringFormat.h"

namespace dd::libxdf::types::elements {
    MMXDFFlag::MMXDFFlag(MMEmbeddedData *embeddedData, std::string title, std::string description, uint8_t maskValue) :
        MMElement("XDFFLAG", {}, true) {
        this->InsertElement(new MMElement("title", std::move(title)));
        this->InsertElement(new MMElement("description", std::move(description)));
        this->InsertElement(embeddedData);
        this->InsertElement(new MMElement("mask", format("{:#x}", maskValue)));
    }
} // elements