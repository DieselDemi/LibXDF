#include "MMXDFConstant.h"
#include "../../XDFile.h"

//TODO(Demi): This has to move in order not to poision other libraries
#ifdef _WIN32

#include <format>

#define format(arg, ...) std::format(arg, __VA_ARGS__)
#else
#include <memory>
template<typename ... Args>
std::string string_format( const std::string& format, Args ... args )
{
    int size_s = std::snprintf( nullptr, 0, format.c_str(), args ... ) + 1; // Extra space for '\0'
    if( size_s <= 0 ){ throw std::runtime_error( "Error during formatting." ); }
    auto size = static_cast<size_t>( size_s );
    std::unique_ptr<char[]> buf( new char[ size ] );
    std::snprintf( buf.get(), size, format.c_str(), args ... );
    return std::string( buf.get(), buf.get() + size - 1 ); // We don't want the '\0' inside
}
#define format(arg, ...) string_format(arg, __VA_ARGS__)
#endif

namespace dd::libxdf::types::elements {
    MMXDFConstant::MMXDFConstant(flags::MMXDFConstantFlags flags) : MMElement() {
        this->name = "XDFCONSTANT";

        InsertAttribute({.name = "uniqueid", .value = this->GetUniqueHexId()});
        InsertAttribute({.name = "flags", .value = format("{:#x}", static_cast<int>(flags))});

        auto *titleElement = new MMElement();
        titleElement->SetName("title");
        titleElement->SetText("TODO Implement titles");

        auto *descriptionElement = new MMElement();
        descriptionElement->SetName("description");
        descriptionElement->SetText("TODO Implement descriptions");

        auto *embeddedDataElement = new MMElement();
        embeddedDataElement->SetName("EMBEDDEDDATA");
        embeddedDataElement->AddAttribute({.name = "mmedaddress", .value = "0"});
        embeddedDataElement->AddAttribute({.name = "mmedelementsizebits", .value = "32"});
        embeddedDataElement->AddAttribute({.name = "mmedmajorstridebits", .value = "0"});
        embeddedDataElement->AddAttribute({.name = "mmedminorstridebits", .value = "0"});

        auto *rangeHighElement = new MMElement();
        rangeHighElement->SetName("rangehigh");
        rangeHighElement->SetText("TODO range value here");

        auto *dataTypeElement = new MMElement();
        dataTypeElement->SetName("datatype");
        dataTypeElement->SetText("TODO data type value here ");

        auto *unitTypeElement = new MMElement();
        unitTypeElement->SetName("unittype");
        unitTypeElement->SetText("TODO data type value here ");

        auto *dalinkElement = new MMElement();
        dalinkElement->SetName("DALINK");
        dalinkElement->AddAttribute({.name="index", .value="0"});

        auto* mathElement = new MMElement();
        mathElement->SetName("MATH");
        mathElement->AddAttribute({.name="equation", .value="X"});
        auto* mathVarElement = new MMElement();
        mathVarElement->SetName("VAR");
        mathVarElement->AddAttribute({.name="id", .value="X"});
        mathElement->AddElement(mathVarElement);

        InsertElement(titleElement);
        InsertElement(descriptionElement);
        InsertElement(embeddedDataElement);
        InsertElement(rangeHighElement);
        InsertElement(dataTypeElement);
        InsertElement(unitTypeElement);
        InsertElement(dalinkElement);
        InsertElement(mathElement);
    }
}