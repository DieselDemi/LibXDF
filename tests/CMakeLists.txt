cmake_minimum_required(VERSION 3.20)

project(libxdf-tests)

set(SRCS
        src/main.cpp
)

add_executable(libxdf-tests ${SRCS})