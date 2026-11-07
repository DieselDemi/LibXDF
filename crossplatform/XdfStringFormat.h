#ifndef XDFCREATOR_XDFSTRINGFORMAT_H
#define XDFCREATOR_XDFSTRINGFORMAT_H

//#ifdef _WIN32
//#include <format>
//#define format(arg, ...) std::format(arg, __VA_ARGS__)
//#else
#include <memory>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <type_traits>
template< typename T >
std::string NumToHex( T i )
{
    using Value = std::remove_cv_t<T>;
    using Unsigned = std::make_unsigned_t<Value>;
    std::stringstream stream;
    stream << "0x"
           << std::setfill ('0') << std::setw(sizeof(T))
           << std::hex << static_cast<uint64_t>(static_cast<Unsigned>(i));
    return stream.str();
}

template<typename ... Args>
std::string string_format(const std::string&, Args ... args) {
    return NumToHex(args...);
}
#define format(arg, ...) string_format(arg, __VA_ARGS__)
//#endif

#endif //XDFCREATOR_XDFSTRINGFORMAT_H
