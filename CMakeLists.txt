cmake_minimum_required(VERSION 3.18)

project (fib NONE)

enable_language(C)

set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_C_COMPILER gcc)

add_executable(fib1 driver.c fib1.c)
target_compile_options(fib1 PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -O2>)
add_executable(fib2 driver.c fib2.c)
target_compile_options(fib2 PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -O2>)
add_executable(fib3 driver.c fib3.c)
target_compile_options(fib3 PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -O2>)
add_executable(fib_integer driver_integer.c integer.c fib_integer.c)
target_compile_options(fib_integer PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -O2>)

add_library(libfib1 OBJECT fib1.c)
target_compile_options(libfib1 PRIVATE -Wall -O2 -save-temps)
add_library(libfib2 OBJECT fib2.c)
target_compile_options(libfib2 PRIVATE -Wall -O2 -save-temps)
add_library(libfib3 OBJECT fib3.c)
target_compile_options(libfib3 PRIVATE -Wall -O2 -save-temps)
