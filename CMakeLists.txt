cmake_minimum_required(VERSION 3.10)

project(eventSystemMain)

# file (GLOB_RECURSE EVENT_SYSTEM_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
# file (GLOB_RECURSE EVENT_SYSTEM_HEADERS CONFIGURE_DEPENDS "src/*.h")

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory("src")

add_compile_options("-fno-permissive")
add_executable(eventSystemMain)
target_sources(eventSystemMain PRIVATE "main.cpp")
target_include_directories(eventSystemMain PRIVATE "src/include/")

target_link_libraries(eventSystemMain eventSystem)