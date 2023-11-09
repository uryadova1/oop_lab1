cmake_minimum_required(VERSION 3.26)
project(lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(main.cpp
        cmake-build-debug/BitArray.cpp
        cmake-build-debug/BitArray.h
        main.cpp)
include(FetchContent)

