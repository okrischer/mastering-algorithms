cmake_minimum_required(VERSION 3.0.0)
project(mastering VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_COMPILER "clang-14")

add_subdirectory(preliminaries)
add_executable(prelim prelim_test.c)
target_link_libraries(prelim PUBLIC preliminaries)
target_include_directories(prelim PUBLIC preliminaries/include include)

include(CTest)
enable_testing()

add_test(NAME pointer COMMAND prelim "pointer")
