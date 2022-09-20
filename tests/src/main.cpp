#include <iostream>
#include <XDFTypes.h>
#include <gtest/gtest.h>

TEST(TestSuiteTest, TestSuiteAssertions) {
    EXPECT_STRNE("HELLO", "WORLD");
    EXPECT_EQ(7 * 6, 42);
}

TEST(GenerationNotEmpty, DocumentIsGenerated) {
    dd::libxdf::types::elements::XDFRootTag rootTag;

    rootTag.AddElement(new dd::libxdf::types::elements::MMXDFHeader(
        dd::libxdf::types::elements::XDFHeaderFlags::UNKNOWN,
        0.f,
        "Hello",
        "Description",
        "Author",
        0,
        0,
        {}
    ));

    EXPECT_STRNE(rootTag.ToString().c_str(), "");
}

TEST(GenerationNotEmpty, DocumentHasASingleElement) {
    dd::libxdf::types::elements::XDFRootTag rootTag;

    rootTag.AddElement(new dd::libxdf::types::elements::MMXDFHeader(
            dd::libxdf::types::elements::XDFHeaderFlags::UNKNOWN,
            0.f,
            "Hello",
            "Description",
            "Author",
            0,
            0,
            {}
    ));

    EXPECT_EQ(rootTag.GetAllElements().size(), 1);

}

TEST(GenerationStringNotEmpty, DocumentHasOutputAsString) {
    dd::libxdf::types::elements::XDFRootTag rootTag;

    rootTag.AddElement(new dd::libxdf::types::elements::MMXDFHeader(
            dd::libxdf::types::elements::XDFHeaderFlags::UNKNOWN,
            0.f, //File Version
            "Example Title", //Title
            "Description", //Description
            "Author", //Author
            0, //Base offset, as an integer
            0, //Base offset subtraction as an integer
            {} //An initializer list of categories
    ));

    rootTag.AddElement(new dd::libxdf::types::elements::MMXDFFlag(
            new dd::libxdf::types::MMEmbeddedData(
                    0 //Address
            ), //Embedded Data
            "Basic Flag",
            "Description",
            0 //Mask value as uint8_t
    ));

    EXPECT_STRNE(rootTag.ToString().c_str(), "");
}


