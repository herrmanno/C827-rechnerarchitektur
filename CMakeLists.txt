cmake_minimum_required(VERSION 3.18)

project (fib NONE)

enable_language(C)

set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_C_COMPILER gcc)

find_package(OpenMP)

add_executable(fib1 driver.c fib1.c)
target_compile_options(fib1 PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -O3>)
add_executable(fib2 driver.c fib2.c)
target_compile_options(fib2 PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -O3>)
add_executable(fib3 driver.c fib3.c)
target_compile_options(fib3 PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -O3>)
add_executable(fib_integer driver_integer.c integer.c fib_integer.c)
target_compile_options(fib_integer PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -O3>)

add_executable(fib3parallel driver_multiple.c fib3.c)
target_compile_options(fib3 PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -O3>)
if(OpenMP_C_CFOUND)
    target_link_libraries(fib3parallel PUBLIC OpenMP::OpenMP_C)
endif()

add_library(libfib1 OBJECT fib1.c)
target_compile_options(libfib1 PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -O3> -save-temps)
add_library(libfib2 OBJECT fib2.c)
target_compile_options(libfib2 PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -O3> -save-temps)
add_library(libfib3 OBJECT fib3.c)
target_compile_options(libfib3 PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -g -O3> -save-temps)

