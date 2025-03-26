cmake_minimum_required(VERSION 3.9)

project(eventSystemMain)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory("src")
add_subdirectory("test")

add_compile_options("-fno-permissive")
add_executable(eventSystemMain)
target_sources(eventSystemMain PRIVATE "main.cpp")
target_include_directories(eventSystemMain PRIVATE "src/include/")
target_link_libraries(eventSystemMain eventSystem)

enable_testing()