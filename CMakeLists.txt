cmake_minimum_required(VERSION 3.15)
project(patmat-testing)
enable_testing()

find_package(GTest)

add_executable(all_tests basic.cpp)
target_compile_options(all_tests PRIVATE -fpattern-matching)
target_link_libraries(all_tests GTest::Main)
gtest_discover_tests(all_tests)
