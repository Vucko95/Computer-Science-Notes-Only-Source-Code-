cmake_minimum_required(VERSION 3.15)
project(UnitTesting C)

set(CMAKE_C_STANDARD 99)

find_library(CUNIT libcunit.a /usr/local/Cellar/cunit/2.1-3/lib)
include_directories(/usr/local/Cellar/cunit/2.1-3/include/CUnit .)

add_executable(UnitTesting main.c maxFunction.c maxFunction.h)


target_link_libraries(UnitTesting PUBLIC ${CUNIT})
