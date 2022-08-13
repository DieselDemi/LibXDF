cmake_minimum_required(VERSION 3.20)

project(libxdf)

set(CMAKE_CXX_STANDARD 23)

set(SRCS
        exceptions/XdfFileException.cpp
        exceptions/XdfFileException.h
        types/MMXDFConstantFlags.h
        types/MMElement.cpp
        types/MMElement.h
        types/MMAttribute.cpp
        types/MMAttribute.h
        types/elements/XDFRootTag.cpp
        types/elements/XDFRootTag.h
        types/elements/MMXDFConstant.cpp
        types/elements/MMXDFConstant.h
        XDFile.cpp
        XDFile.h
        types/elements/MMXDFHeader.cpp types/elements/MMXDFHeader.h types/elements/MMXDFChecksum.cpp types/elements/MMXDFChecksum.h types/elements/MMXDFFlag.cpp types/elements/MMXDFFlag.h)

add_library(libxdf STATIC ${SRCS})

target_link_libraries(libxdf libconsole sqlite3)

#set_target_properties(libxdf PROPERTIES LINKER_LANGUAGE C)

install(TARGETS libxdf
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)