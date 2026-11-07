#include <iostream>
#include <XDFTypes.h>
#include <XDFile.h>
#include <gtest/gtest.h>

#include <filesystem>
#include <algorithm>

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

TEST(Parsing, UsesConcreteObjectGraph) {
    dd::libxdf::XDFile file;
    file.ReadFromString(R"(<XDFFORMAT version="1.60">
        <XDFTABLE uniqueid="28.0000" vendor="kept">
            <title>Example &amp; Test</title>
            <XDFAXIS id="z">
                <EMBEDDEDDATA mmedaddress="17C034" mmedelementsizebits="16" mmedrowcount="2" mmedcolcount="3" mmedmajorstridebits="-32" mmedminorstridebits="0" />
                <MATH equation="X * 0.5"><VAR id="X" /></MATH>
                <VENDOR_EXTENSION enabled="yes" />
            </XDFAXIS>
        </XDFTABLE>
    </XDFFORMAT>)");

    auto* table = dynamic_cast<MMXDFTable*>(file.GetRootTag().GetElementByName("XDFTABLE"));
    ASSERT_NE(table, nullptr);
    EXPECT_EQ(table->GetAttribute("uniqueid").value, "28.0000");
    EXPECT_EQ(table->GetAttribute("vendor").value, "kept");

    auto* axis = table->GetAxis("z");
    ASSERT_NE(axis, nullptr);
    auto* data = axis->GetEmbeddedData();
    ASSERT_NE(data, nullptr);
    EXPECT_EQ(data->GetAddress(), 0x17C034u);
    EXPECT_EQ(data->GetElementSizeBits(), 16u);
    EXPECT_EQ(data->GetRowCount(), 2u);
    EXPECT_EQ(data->GetColumnCount(), 3u);
    EXPECT_EQ(data->GetMajorStrideBits(), -32);

    const auto math = axis->GetMathElements();
    ASSERT_EQ(math.size(), 1u);
    EXPECT_EQ(math.front()->GetEquation(), "X * 0.5");
    ASSERT_EQ(math.front()->GetVariables().size(), 1u);
    EXPECT_EQ(math.front()->GetVariables().front()->GetVariableId(), "X");
    EXPECT_NE(axis->GetElementByName("VENDOR_EXTENSION"), nullptr);

    const auto serialized = file.Print();
    EXPECT_NE(serialized.find("Example &amp; Test"), std::string::npos);

    dd::libxdf::XDFile reparsed;
    EXPECT_NO_THROW(reparsed.ReadFromString(serialized));
    EXPECT_NE(reparsed.GetRootTag().GetElementByName("XDFTABLE"), nullptr);
}

TEST(Parsing, RejectsMalformedXml) {
    dd::libxdf::XDFile file;
    EXPECT_THROW(file.ReadFromString("<XDFFORMAT><XDFTABLE></XDFFORMAT>"), XdfFileException);
}

TEST(Parsing, LoadsAndRoundTripsExampleCorpus) {
    const std::vector<std::pair<std::string, std::size_t>> examples = {
            {"ECM555_2.xdf", 7},
            {"12656942-generated.xdf", 40},
            {"FS0Q00.xdf", 1046},
    };

    for (const auto& [name, expectedTopLevelCount] : examples) {
        SCOPED_TRACE(name);
        const auto path = std::filesystem::path(LIBXDF_SOURCE_DIR) / "examples" / name;

        dd::libxdf::XDFile file;
        ASSERT_NO_THROW(file.ReadFromDisk(path.string()));
        EXPECT_EQ(file.GetRootTag().GetAllElements().size(), expectedTopLevelCount);
        const auto diagnostics = file.Validate();
        EXPECT_TRUE(std::none_of(diagnostics.begin(), diagnostics.end(), [](const auto& diagnostic) {
            return diagnostic.severity == dd::libxdf::DiagnosticSeverity::ERROR;
        }));

        const auto serialized = file.Print();
        dd::libxdf::XDFile reparsed;
        ASSERT_NO_THROW(reparsed.ReadFromString(serialized));
        EXPECT_EQ(reparsed.GetRootTag().GetAllElements().size(), expectedTopLevelCount);
    }
}

TEST(Generation, RichEmbeddedDataSupportsBinLayout) {
    MMEmbeddedData data(
            0x123456u,
            16,
            -32,
            160,
            0x04u,
            8u,
            12u);

    EXPECT_EQ(data.GetAddress(), 0x123456u);
    EXPECT_EQ(data.GetElementSizeBits(), 16u);
    EXPECT_EQ(data.GetMajorStrideBits(), -32);
    EXPECT_EQ(data.GetMinorStrideBits(), 160);
    EXPECT_EQ(data.GetTypeFlags(), 0x04u);
    EXPECT_EQ(data.GetRowCount(), 8u);
    EXPECT_EQ(data.GetColumnCount(), 12u);
}

TEST(Validation, ReportsSemanticProblemsWithoutRejectingXml) {
    dd::libxdf::XDFile file;
    ASSERT_NO_THROW(file.ReadFromString(R"(<XDFFORMAT version="1.60">
        <XDFTABLE uniqueid="0x10"><XDFAXIS id="y"><indexcount>2</indexcount><LABEL index="0" value="a"/></XDFAXIS></XDFTABLE>
        <XDFTABLE uniqueid="0x10"/>
    </XDFFORMAT>)"));

    const auto diagnostics = file.Validate();
    EXPECT_GE(diagnostics.size(), 2u);
    EXPECT_TRUE(std::all_of(diagnostics.begin(), diagnostics.end(), [](const auto& diagnostic) {
        return diagnostic.severity == dd::libxdf::DiagnosticSeverity::WARNING;
    }));
}
