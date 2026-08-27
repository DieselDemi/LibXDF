cmake_minimum_required(VERSION 3.20)
project(libxdf-tests)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(libxdf-tests src/main.cpp)
target_compile_definitions(libxdf-tests PRIVATE LIBXDF_SOURCE_DIR="${CMAKE_SOURCE_DIR}")

if(TARGET libxdf-static)
    target_link_libraries(libxdf-tests libxdf-static GTest::gtest_main)
elseif(TARGET libxdf-shared)
    target_link_libraries(libxdf-tests libxdf-shared GTest::gtest_main)
else()
    message(FATAL_ERROR "LibXDF tests require a static or shared library target")
endif()

add_test(NAME libxdf-tests COMMAND libxdf-tests)
