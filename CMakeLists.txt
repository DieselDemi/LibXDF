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
        types/elements/MMXDFHeader.cpp
        types/elements/MMXDFHeader.h
        types/elements/MMXDFChecksum.cpp
        types/elements/MMXDFChecksum.h
        types/elements/MMXDFFlag.cpp
        types/elements/MMXDFFlag.h
        types/elements/MMXDFAxis.cpp
        types/elements/MMXDFAxis.h
        types/MMEmbeddedData.cpp
        types/MMEmbeddedData.h
        types/elements/MMXDFTable.cpp
        types/elements/MMXDFTable.h
        types/MMDefaultsElement.cpp
        types/MMDefaultsElement.h
        types/MMCategory.cpp
        types/MMCategory.h
        types/MMMath.cpp
        types/MMMath.h)

#TODO Make a CMake variable control this
#Comment this line for dynamic lib
add_library(libxdf STATIC ${SRCS})
#Uncomment this line for dynamic lib
#add_library(libxdf SHARED ${SRCS})

install(TARGETS libxdf
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)