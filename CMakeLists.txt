cmake_minimum_required(VERSION 3.0.0)
project(mastering VERSION 0.1.0 LANGUAGES C)

add_subdirectory(preliminaries)
add_executable(prelim src/prelim.c test/pointer.c test/recursion.c bench/bm.c)
target_link_libraries(prelim PUBLIC preliminaries)
target_include_directories(prelim PUBLIC preliminaries/include include)

add_subdirectory(datastructures)
add_executable(ds src/ds.c test/hanoi.c test/events.c)
target_link_libraries(ds PUBLIC datastructures)
target_include_directories(ds PUBLIC datastructures/include include)

include(CTest)
enable_testing()

add_test(NAME prelim_pointer COMMAND prelim 1)
add_test(NAME prelim_recursion COMMAND prelim 2)
add_test(NAME prelim_bench COMMAND prelim 3)

add_test(NAME ds_hanoi COMMAND ds 1)
add_test(NAME ds_events COMMAND ds 2)