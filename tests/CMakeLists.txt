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

include_directories(../include)

add_executable(libxdf-tests src/main.cpp)

target_link_libraries(libxdf-tests libxdf-static GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(libxdf-tests)