cmake_minimum_required(VERSION 3.0.0)
project(mastering VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_subdirectory(preliminaries)

add_executable(prelim prelim.c)
target_link_libraries(prelim PUBLIC preliminaries)

include_directories(include)
