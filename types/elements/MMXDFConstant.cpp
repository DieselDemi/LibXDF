#include "MMXDFConstant.h"
#include "../MMEmbeddedData.h"
#include "../MMMath.h"

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
    MMXDFConstant::MMXDFConstant(flags::MMXDFConstantFlags flags) :
            MMElement("XDFCONSTANT",
                      {
                              {.name = "uniqueid", .value = this->GetUniqueHexId()},
                              {.name = "flags", .value = format("{:#x}",static_cast<int>(flags))}
                      }
            ) {

        InsertElement(new MMElement("title", "TODO Implement titles"));
        InsertElement(new MMElement("description", "TODO Implement descriptions"));
        InsertElement(new MMEmbeddedData(10)); //TODO Address
        InsertElement(new MMElement("rangehigh", "TODO range value here"));
        InsertElement(new MMElement("datatype", "TODO - data type value"));
        InsertElement(new MMElement("unittype", "TODO data type value here"));
        InsertElement(new MMElement("DALINK", {{.name="index", .value="0"}}));
        InsertElement(new MMMath("X+Y")); //TODO Equations
    }
}