#include "MMXDFHeader.h"

namespace dd::libxdf::types::elements {


    MMXDFHeader::MMXDFHeader() {
        this->name = "XDFHEADER";

        auto* flagsElement = new MMElement();
        flagsElement->SetName("flags");
        flagsElement->SetText("TODO - Flags");

        auto* fileVersionElement = new MMElement();
        fileVersionElement->SetName("fileversion");
        fileVersionElement->SetText("TODO - File Version");

        auto* defTitleElement = new MMElement();
        defTitleElement->SetName("deftitle");
        defTitleElement->SetText("TODO - Title");

        auto* descriptionElement = new MMElement();
        descriptionElement->SetName("description");
        descriptionElement->SetText("TODO - Description Text");

        auto* authorElement = new MMElement();
        authorElement->SetName("author");
        authorElement->SetText("TODO - Author name");

        auto* baseOffsetElement = new MMElement();
        baseOffsetElement->SetName("BASEOFFSET");
        baseOffsetElement->AddAttribute({.name="offset",.value="TODO - offset value"});
        baseOffsetElement->AddAttribute({.name="subtract",.value="TODO - subtract value"});

        auto* defaultsElement = new MMElement();
        defaultsElement->SetName("DEFAULTS");
        defaultsElement->AddAttribute({.name="datasizeinbits", .value="TODO - fix these attributes"});
        defaultsElement->AddAttribute({.name="sigdigits", .value="TODO - fix these attributes"});
        defaultsElement->AddAttribute({.name="outputtype", .value="TODO - fix these attributes"});
        defaultsElement->AddAttribute({.name="signed", .value="TODO - fix these attributes"});
        defaultsElement->AddAttribute({.name="lsbfirst", .value="TODO - fix these attributes"});
        defaultsElement->AddAttribute({.name="float", .value="TODO - fix these attributes"});

        auto* regionElement = new MMElement();
        regionElement->SetName("REGION");
        regionElement->AddAttribute({.name="type",.value="TODO - fix these attributes"});
        regionElement->AddAttribute({.name="startaddress",.value="TODO - fix these attributes"});
        regionElement->AddAttribute({.name="size",.value="TODO - fix these attributes"});
        regionElement->AddAttribute({.name="regioncolor",.value="TODO - fix these attributes"});
        regionElement->AddAttribute({.name="regionflags",.value="TODO - fix these attributes"});
        regionElement->AddAttribute({.name="name",.value="TODO - fix these attributes"});
        regionElement->AddAttribute({.name="desc",.value="TODO - fix these attributes"});

        auto* categoryElement = new MMElement();
        categoryElement->SetName("CATEGORY");
        categoryElement->AddAttribute({.name="index", .value="TODO - fix these attributes"});
        categoryElement->AddAttribute({.name="name", .value="TODO - fix these attributes"});

        this->InsertElement(flagsElement);
        this->InsertElement(fileVersionElement);
        this->InsertElement(defTitleElement);
        this->InsertElement(descriptionElement);
        this->InsertElement(authorElement);
        this->InsertElement(baseOffsetElement);
        this->InsertElement(defaultsElement);
        this->InsertElement(regionElement);
        this->InsertElement(categoryElement);
    }


    std::string MMXDFHeader::ToString() {
        return MMElement::ToString();
    }
} // elements