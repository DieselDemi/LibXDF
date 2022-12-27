#include "../../include/elements/MMXDFHeader.h"
#include "../../include/MMDefaultsElement.h"

namespace dd::libxdf::types::elements {


    MMXDFHeader::MMXDFHeader(enums::HeaderFlags flags,
                             float fileVersion,
                             std::string title,
                             std::string description,
                             std::string author,
                             uint32_t offset,
                             uint32_t offsetSubtract,
                             MMRegion* region,
                             std::initializer_list<MMCategory *> categories) : MMElement("XDFHEADER")
    {
        this->InsertElement(new MMElement("flags", std::to_string((uint8_t)flags)));
        this->InsertElement(new MMElement("fileversion", std::to_string(fileVersion)));
        this->InsertElement(new MMElement("deftitle", std::move(title)));
        this->InsertElement(new MMElement("description", std::move(description)));
        this->InsertElement(new MMElement("author", std::move(author)));
        this->InsertElement(new MMElement("BASEOFFSET", {{.name="offset", .value="TODO - offset value"}, {.name="subtract", .value="TODO - subtract value"}}));
        this->InsertElement(new MMDefaultsElement());

        this->InsertElement(region);

        for(auto category : categories) {
            this->InsertElement(category);
        }
    }


    std::string MMXDFHeader::ToString() {
        return MMElement::ToString();
    }
} // elements