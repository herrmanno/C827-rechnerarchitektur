cmake_minimum_required(VERSION 3.18)

project (fib NONE)

enable_language(C)

set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_C_COMPILER gcc)

find_package(OpenMP)

IF(OpenMP_C__FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp")
ENDIF()

add_executable(fib_rec driver.c fib_rec.c)
target_compile_options(fib_rec PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -O3>)
add_executable(fib_rec_cache driver.c fib_rec_cache.c)
target_compile_options(fib_rec_cache PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -O3>)
add_executable(fib_tailrec driver.c fib_tailrec.c)
target_compile_options(fib_tailrec PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -O3>)
add_executable(fib_iterative driver.c fib_iterative.c)
target_compile_options(fib_iterative PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -O3>)
add_executable(fib_iterative_cache driver.c fib_iterative_cache.c)
target_compile_options(fib_iterative_cache PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -O3>)
add_executable(fib_unroll driver.c fib_unroll.c)
target_compile_options(fib_unroll PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -O3>)

add_executable(fib_integer driver_integer.c integer.c fib_integer.c)
target_compile_options(fib_integer PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -O3>)

if(OpenMP_C_CFOUND)
    add_executable(fibparallel driver_multiple.c fib_unroll.c)
    target_compile_options(fibparallel PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -O3>)
    target_link_libraries(fibparallel PUBLIC OpenMP::OpenMP_C)
endif()

add_library(libfib_rec OBJECT fib_rec.c)
target_compile_options(libfib_rec PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -O3> -save-temps)
add_library(libfib_rec_cache OBJECT fib_rec_cache.c)
target_compile_options(libfib_rec_cache PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -O3> -save-temps)
add_library(libfib_tailrec OBJECT fib_tailrec.c)
target_compile_options(libfib_tailrec PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -g -O3> -save-temps)
add_library(libfib_iterative OBJECT fib_iterative.c)
target_compile_options(libfib_iterative PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -g -O3> -save-temps)
add_library(libfib_iterative_cache OBJECT fib_iterative_cache.c)
target_compile_options(libfib_iterative_cache PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -g -O3> -save-temps)
add_library(libfib_unroll OBJECT fib_unroll.c)
target_compile_options(libfib_unroll PRIVATE -Wall $<$<CONFIG:Debug>: -g > $<$<CONFIG:Release>: -g -O3> -save-temps)

