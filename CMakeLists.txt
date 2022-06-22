cmake_minimum_required(VERSION 3.18)

project (fib NONE)

enable_language(C)

set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_C_COMPILER gcc)

include_directories(
	${PROJECT_SOURCE_DIR}/src
)

find_package(OpenMP)

IF(OpenMP_C__FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp")
ENDIF()

add_executable(fib_rec src/driver.c src/fib_rec.c)
target_compile_options(fib_rec PRIVATE -Wall -g $<$<CONFIG:Debug>: -O0 > $<$<CONFIG:Release>: -O3>)
add_executable(fib_rec_cache src/driver.c src/fib_rec_cache.c)
target_compile_options(fib_rec_cache PRIVATE -Wall -g $<$<CONFIG:Debug>: -O0 > $<$<CONFIG:Release>: -O3>)
add_executable(fib_tailrec src/driver.c src/fib_tailrec.c)
target_compile_options(fib_tailrec PRIVATE -Wall -g $<$<CONFIG:Debug>: -O0 > $<$<CONFIG:Release>: -O3>)
add_executable(fib_iterative src/driver.c src/fib_iterative.c)
target_compile_options(fib_iterative PRIVATE -Wall -g $<$<CONFIG:Debug>: -O0 > $<$<CONFIG:Release>: -O3>)
add_executable(fib_iterative_cache src/driver.c src/fib_iterative_cache.c)
target_compile_options(fib_iterative_cache PRIVATE -Wall -g $<$<CONFIG:Debug>: -O0 > $<$<CONFIG:Release>: -O3>)
add_executable(fib_unroll src/driver.c src/fib_unroll.c)
target_compile_options(fib_unroll PRIVATE -Wall -g $<$<CONFIG:Debug>: -O0 > $<$<CONFIG:Release>: -O3>)

add_executable(fib_integer src/driver_integer.c src/integer.c src/fib_integer.c)
target_compile_options(fib_integer PRIVATE -Wall -g $<$<CONFIG:Debug>: -O0 > $<$<CONFIG:Release>: -O3>)

if(OpenMP_C_CFOUND)
    add_executable(fibparallel src/driver_multiple.c src/fib_unroll.c)
    target_compile_options(fibparallel PRIVATE -Wall -g $<$<CONFIG:Debug>: -O0 > $<$<CONFIG:Release>: -O3>)
    target_link_libraries(fibparallel PUBLIC OpenMP::OpenMP_C)
endif()

add_library(libfib_rec OBJECT src/fib_rec.c)
target_compile_options(libfib_rec PRIVATE -Wall -g $<$<CONFIG:Debug>: -O0 > $<$<CONFIG:Release>: -O3> -save-temps)
add_library(libfib_rec_cache OBJECT src/fib_rec_cache.c)
target_compile_options(libfib_rec_cache PRIVATE -Wall -g $<$<CONFIG:Debug>: -O0 > $<$<CONFIG:Release>: -O3> -save-temps)
add_library(libfib_tailrec OBJECT src/fib_tailrec.c)
target_compile_options(libfib_tailrec PRIVATE -Wall -g $<$<CONFIG:Debug>: -O0 > $<$<CONFIG:Release>: -O3> -save-temps)
add_library(libfib_iterative OBJECT src/fib_iterative.c)
target_compile_options(libfib_iterative PRIVATE -Wall -g $<$<CONFIG:Debug>: -O0 > $<$<CONFIG:Release>: -O3> -save-temps)
add_library(libfib_iterative_cache OBJECT src/fib_iterative_cache.c)
target_compile_options(libfib_iterative_cache PRIVATE -Wall -g $<$<CONFIG:Debug>: -O0 > $<$<CONFIG:Release>: -O3> -save-temps)
add_library(libfib_unroll OBJECT src/fib_unroll.c)
target_compile_options(libfib_unroll PRIVATE -Wall -g $<$<CONFIG:Debug>: -O0 > $<$<CONFIG:Release>: -O3> -save-temps)

