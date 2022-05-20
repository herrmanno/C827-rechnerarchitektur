mkdir -p build/debug
mkdir -p build/release
cmake -B build/debug -S . -D CMAKE_BUILD_TYPE=Debug
cmake -B build/release -S . -D CMAKE_BUILD_TYPE=Release
cmake --build build/debug
cmake --build build/release

# Create objdump files
echo "Creating objdump files"
objdump -d --source build/debug/CMakeFiles/libfib3.dir/fib3.c.o > build/debug/fib3.objdump
objdump -d --source build/release/CMakeFiles/libfib3.dir/fib3.c.o > build/release/fib3.objdump

# Create risc files and objdumps
if [ -f ~/risc-compiler/bin/riscv64-unknown-elf-gcc ]; then
    echo "Compiling for RISC"
    ~/risc-compiler/bin/riscv64-unknown-elf-gcc -O0 -g -c fib3.c -o build/debug/fib3.risc.o
    ~/risc-compiler/bin/riscv64-unknown-elf-gcc -O3 -g -c fib3.c -o build/release/fib3.risc.o

    ~/risc-compiler/bin/riscv64-unknown-elf-objdump -d --source build/debug/fib3.risc.o > build/debug/fib3.risc.objdump
    ~/risc-compiler/bin/riscv64-unknown-elf-objdump -d --source build/release/fib3.risc.o > build/release/fib3.risc.objdump
fi
