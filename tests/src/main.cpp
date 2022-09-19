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

TEST(GenerationNotEmpty, DocumentHasMultipleElements) {
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


