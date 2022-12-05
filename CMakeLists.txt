cmake_minimum_required(VERSION 3.20)

project(libxdf)

set(CMAKE_CXX_STANDARD 23)

option(LIBXDF_BUILD_TESTS "Build test cases" ON)
option(LIBXDF_BUILD_STATIC "Build as static library" ON)
option(LIBXDF_BUILD_SHARED "Build as shared library" ON)

set(SRCS
        exceptions/XdfFileException.cpp
        exceptions/XdfFileException.h
        types/MMElement.cpp
        include/MMElement.h
        types/MMAttribute.cpp
        include/MMAttribute.h
        types/elements/XDFRootTag.cpp
        include/elements/XDFRootTag.h
        types/elements/MMXDFConstant.cpp
        include/elements/MMXDFConstant.h
        XDFile.cpp
        include/XDFile.h
        types/elements/MMXDFHeader.cpp
        include/elements/MMXDFHeader.h
        types/elements/MMXDFChecksum.cpp
        include/elements/MMXDFChecksum.h
        types/elements/MMXDFFlag.cpp
        include/elements/MMXDFFlag.h
        types/elements/MMXDFAxis.cpp
        include/elements/MMXDFAxis.h
        types/MMEmbeddedData.cpp
        include/MMEmbeddedData.h
        types/elements/MMXDFTable.cpp
        include/elements/MMXDFTable.h
        types/MMDefaultsElement.cpp
        include/MMDefaultsElement.h
        types/MMCategory.cpp
        include/MMCategory.h
        types/MMMath.cpp
        include/MMMath.h
        crossplatform/XdfStringFormat.h
        types/elements/MMXDFFunction.cpp
        include/elements/MMXDFFunction.h
        types/elements/MMXDFPatch.cpp
        include/elements/MMXDFPatch.h
        types/elements/MMXDFPatchEntry.cpp
        include/elements/MMXDFPatchEntry.h
        types/MMRegion.cpp
        include/MMRegion.h
        include/MMTypes.h)

include_directories(include)

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