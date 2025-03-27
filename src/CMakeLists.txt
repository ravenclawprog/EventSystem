cmake_minimum_required(VERSION 3.9)

project(eventSystem VERSION 0.0.1 DESCRIPTION "event system library TBD")


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_library(eventSystem STATIC
    include/abstract_delegate.h
    include/delegate.h
    # src/delegate.cpp
)
set_target_properties(eventSystem PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(eventSystem PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(eventSystem PROPERTIES PUBLIC_HEADER include/delegate.h)

target_include_directories(eventSystem PRIVATE include)
# target_include_directories(eventSystem PRIVATE src)