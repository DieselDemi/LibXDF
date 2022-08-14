#include <format>

#include "MMXDFFlag.h"
#include "../MMEmbeddedData.h"

namespace dd::libxdf::types::elements {
    MMXDFFlag::MMXDFFlag(std::string title, std::string description, uint8_t maskValue) : MMElement("XDFFLAG", {{.name = "uniqueid", .value = this->GetUniqueHexId()}}) {
        this->InsertElement(new MMElement("title", std::move(title)));
        this->InsertElement(new MMElement("description", std::move(description)));
        this->InsertElement(new MMEmbeddedData(0)); //TODO Embedded data
        this->InsertElement(new MMElement("mask", std::format("{:#x}", maskValue)));
    }
} // elements