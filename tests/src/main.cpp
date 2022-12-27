#include <iostream>
#include <XDFTypes.h>
#include <gtest/gtest.h>

using namespace dd::libxdf::types;
using namespace dd::libxdf::types::elements;

TEST(TestSuiteTest, TestSuiteAssertions) {
    EXPECT_STRNE("HELLO", "WORLD");
    EXPECT_EQ(7 * 6, 42);
}

TEST(GenerationNotEmpty, DocumentIsGenerated) {
    XDFRootTag rootTag;

    rootTag.AddElement(new MMXDFHeader(
        enums::HeaderFlags::UNKNOWN,
        0.f,
        "Hello",
        "Description",
        "Author",
        0,
        0,
        new MMRegion(
                enums::RegionType::DEFAULT,
                0,
                0,
                enums::RegionFlag::DEFAULT,
                "No Name",
                "No Description"
        ),
        {}
    ));

    EXPECT_STRNE(rootTag.ToString().c_str(), "");
}

TEST(GenerationNotEmpty, DocumentHasASingleElement) {
    XDFRootTag rootTag;

    rootTag.AddElement(new MMXDFHeader(
            enums::HeaderFlags::UNKNOWN,
            0.f,
            "Hello",
            "Description",
            "Author",
            0,
            0,
            new MMRegion(
                    enums::RegionType::DEFAULT,
                    0,
                    0,
                    enums::RegionFlag::DEFAULT,
                    "No Name",
                    "No Description"
            ),
            {}
    ));

    EXPECT_EQ(rootTag.GetAllElements().size(), 1);

}

TEST(GenerationStringNotEmpty, DocumentHasOutputAsString) {
    XDFRootTag rootTag;

    rootTag.AddElement(new MMXDFHeader(
            enums::HeaderFlags::UNKNOWN,
            0.f, //File Version
            "Example Title", //Title
            "Description", //Description
            "Author", //Author
            0, //Base offset, as an integer
            0, //Base offset subtraction as an integer
            new MMRegion(
                enums::RegionType::DEFAULT,
                0,
                0,
                enums::RegionFlag::DEFAULT,
                "No Name",
                "No Description"
            ),
            {} //An initializer list of categories
    ));

    rootTag.AddElement(new MMXDFFlag(
            new MMEmbeddedData(
                    0 //Address
            ), //Embedded Data
            "Basic Flag",
            "Description",
            0 //Mask value as uint8_t
    ));

    EXPECT_STRNE(rootTag.ToString().c_str(), "");
}

/**
 * Region generation testing
 */

//<REGION type="0xFFFFFFFF" startaddress="0x0" size="700000" regionflags="0x0" name="Binary File" desc="" />
TEST(RegionTest, RegionElementGeneration) {
    auto* region = new MMRegion(enums::RegionType::DEFAULT, 0, 700000, enums::RegionFlag::DEFAULT, "Binary File", "");
    EXPECT_STREQ(region->ToString().c_str(), "<REGION desc=\"\" name=\"Binary File\" regionflags=\"0x0000\" size=\"0xaae60\" startaddress=\"0x0000\" type=\"0xffffffff\"/>\n");
    delete region;
}
