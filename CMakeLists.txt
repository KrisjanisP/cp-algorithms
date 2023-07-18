cmake_minimum_required(VERSION 3.14)

project(Algorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB_RECURSE SOURCES "src/*.hpp")

add_executable(test_SparseTable ${SOURCES} tests/test_SparseTable.cpp)
target_link_libraries(test_SparseTable GTest::GTest GTest::Main)

gtest_discover_tests(test_SparseTable)

