cmake_minimum_required(VERSION 3.9)
project(eventSystemUT)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

# enable_testing()

add_executable(
  solidSolutionTest
  solidSolutionTest.cpp
)
target_include_directories(solidSolutionTest PRIVATE "../src/include/")
target_link_libraries(
    solidSolutionTest
    GTest::gtest_main
    eventSystem
)

include(GoogleTest)
gtest_discover_tests(solidSolutionTest)

add_executable(
  templateSolutionTest
  templateSolutionTest.cpp
)
target_include_directories(templateSolutionTest PRIVATE "../src/include/")
target_link_libraries(
    templateSolutionTest
    GTest::gtest_main
    eventSystem
)

include(GoogleTest)
gtest_discover_tests(templateSolutionTest)