cmake_minimum_required(VERSION 3.20)

project(libxdf)

set(CMAKE_CXX_STANDARD 23)

option(LIBXDF_BUILD_TESTS "Build test cases" ON)
option(LIBXDF_BUILD_STATIC "Build as static library" ON)
option(LIBXDF_BUILD_SHARED "Build as shared library" ON)

set(SRCS
        exceptions/XdfFileException.cpp
        exceptions/XdfFileException.h
        types/XDFConstantFlags.h
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
        types/MMMath.h
        crossplatform/XdfStringFormat.h
        types/elements/MMXDFFunction.cpp
        types/elements/MMXDFFunction.h
        types/elements/MMXDFPatch.cpp
        types/elements/MMXDFPatch.h
        types/elements/MMXDFPatchEntry.cpp
        types/elements/MMXDFPatchEntry.h
        types/MMRegion.cpp types/MMRegion.h)

if(LIBXDF_BUILD_TESTS)
    add_subdirectory(tests)
endif()


if(LIBXDF_BUILD_STATIC)
    add_library(libxdf-static STATIC ${SRCS})

    install(TARGETS libxdf-static
            LIBRARY DESTINATION lib
            ARCHIVE DESTINATION lib)
endif()

if(LIBXDF_BUILD_SHARED)
    add_library(libxdf-shared SHARED ${SRCS})

    install(TARGETS libxdf-shared
            LIBRARY DESTINATION lib
            ARCHIVE DESTINATION lib)
endif()