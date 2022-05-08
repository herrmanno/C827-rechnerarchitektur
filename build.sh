mkdir -p build/debug
mkdir -p build/release
cmake -B build/debug -S . -D CMAKE_BUILD_TYPE=Debug
cmake -B build/release -S . -D CMAKE_BUILD_TYPE=Release
cmake --build build/debug
cmake --build build/release

# Create objdump files
objdump -d --source build/debug/CMakeFiles/libfib3.dir/fib3.c.o > build/debug/fib3.objdump
objdump -d --source build/release/CMakeFiles/libfib3.dir/fib3.c.o > build/release/fib3.objdump
