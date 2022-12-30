#include "../../include/elements/MMXDFFlag.h"
#include "../../include/MMEmbeddedData.h"
#include "../../crossplatform/XdfStringFormat.h"

namespace dd::libxdf::types::elements {
    MMXDFFlag::MMXDFFlag(MMEmbeddedData *embeddedData, std::string title, std::string description, uint8_t maskValue) :
        MMElement("XDFFLAG", enums::ElementType::FLAG, {}, true) {
        this->InsertElement(new MMElement("title", enums::ElementType::GENERIC, std::move(title)));
        this->InsertElement(new MMElement("description", enums::ElementType::GENERIC, std::move(description)));
        this->InsertElement(embeddedData);
        this->InsertElement(new MMElement("mask", enums::ElementType::GENERIC, format("{:#x}", maskValue)));
    }
} // elements