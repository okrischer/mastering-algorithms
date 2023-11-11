cmake_minimum_required(VERSION 3.0.0)
project(mastering VERSION 0.1.0 LANGUAGES C)

add_subdirectory(preliminaries)
add_executable(prelim prelim.c)
target_link_libraries(prelim PUBLIC preliminaries)

include(CTest)
enable_testing()

add_test(NAME pointer COMMAND prelim "pointer")