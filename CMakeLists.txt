cmake_minimum_required(VERSION 3.26)
project(lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab1 main.cpp
        BitArray/BitArray.cpp
        BitArray/BitArray.h
        test.cpp
        BitArray/BitArray.cpp)

set(CMAKE_OSX_DEPLOYMENT_TARGET "14.0")

add_executable(Test test.cpp)

add_subdirectory(BitArray)

target_include_directories(Test PRIVATE lab1)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
FetchContent_MakeAvailable(googletest)

target_link_libraries(Test PRIVATE BitArray_t gtest_main)