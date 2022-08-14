#include "MMXDFHeader.h"
#include "../MMDefaultsElement.h"

namespace dd::libxdf::types::elements {


    MMXDFHeader::MMXDFHeader(XDFHeaderFlags flags,
                             float fileVersion,
                             std::string title,
                             std::string description,
                             std::string author,
                             uint32_t offset,
                             uint32_t offsetSubtract,
                             std::initializer_list<MMCategory *> categories) : MMElement("XDFHEADER")
    {
        this->InsertElement(new MMElement("flags", std::to_string((uint8_t)flags)));
        this->InsertElement(new MMElement("fileversion", std::to_string(fileVersion)));
        this->InsertElement(new MMElement("deftitle", std::move(title)));
        this->InsertElement(new MMElement("description", std::move(description)));
        this->InsertElement(new MMElement("author", std::move(author)));
        this->InsertElement(new MMElement("BASEOFFSET", {{.name="offset", .value="TODO - offset value"}, {.name="subtract", .value="TODO - subtract value"}}));
        this->InsertElement(new MMDefaultsElement());
        //TODO(Demi) Move this to its own class
        this->InsertElement(new MMElement("REGION", {
                {.name="type", .value="TODO - fix these attributes"},
                {.name="startaddress", .value="TODO - fix these attributes"},
                {.name="size", .value="TODO - fix these attributes"},
                {.name="regioncolor", .value="TODO - fix these attributes"},
                {.name="regionflags", .value="TODO - fix these attributes"},
                {.name="name", .value="TODO - fix these attributes"},
                {.name="desc", .value="TODO - fix these attributes"}
        }));

        for(auto category : categories) {
            this->InsertElement(category);
        }
    }


    std::string MMXDFHeader::ToString() {
        return MMElement::ToString();
    }
} // elements