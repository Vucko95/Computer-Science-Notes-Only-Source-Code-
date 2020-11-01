cmake_minimum_required(VERSION 3.15)
project(TriangleTesting C)

set(CMAKE_C_STANDARD 99)

find_library(CUNIT libcunit.a <dir_of_libcunit>)

include_directories(<dir_of_include_files> .)

add_executable(TriangleTesting main.c  triangle.c triangle.h)


target_link_libraries(TriangleTesting PUBLIC ${CUNIT})
