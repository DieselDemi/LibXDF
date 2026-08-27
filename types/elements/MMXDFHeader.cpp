#include "../../include/elements/MMXDFHeader.h"
#include "../../include/MMDefaultsElement.h"

namespace dd::libxdf::types::elements {
    MMXDFHeader::MMXDFHeader(ParsedTag) : MMElement("XDFHEADER", enums::ElementType::HEADER) {}


    MMXDFHeader::MMXDFHeader(enums::HeaderFlags flags,
                             float fileVersion,
                             std::string title,
                             std::string description,
                             std::string author,
                             uint32_t offset,
                             uint32_t offsetSubtract,
                             MMRegion* region,
                             std::initializer_list<MMCategory *> categories) : MMElement("XDFHEADER", enums::ElementType::HEADER)
    {
        this->InsertElement(new MMElement("flags", enums::ElementType::GENERIC, std::to_string((uint8_t)flags)));
        this->InsertElement(new MMElement("fileversion", enums::ElementType::GENERIC, std::to_string(fileVersion)));
        this->InsertElement(new MMElement("deftitle", enums::ElementType::GENERIC, std::move(title)));
        this->InsertElement(new MMElement("description", enums::ElementType::GENERIC, std::move(description)));
        this->InsertElement(new MMElement("author", enums::ElementType::GENERIC, std::move(author)));
        this->InsertElement(new MMElement("BASEOFFSET", enums::ElementType::GENERIC, {
                {.name="offset", .value=std::to_string(offset)},
                {.name="subtract", .value=std::to_string(offsetSubtract)}}));
        this->InsertElement(new MMDefaultsElement());

        if (region != nullptr) this->InsertElement(region);

        for(auto category : categories) {
            if (category != nullptr) this->InsertElement(category);
        }
    }


    std::string MMXDFHeader::ToString() {
        return MMElement::ToString();
    }
} // elements
