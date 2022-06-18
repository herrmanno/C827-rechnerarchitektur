#!/bin/bash
mkdir -p build/debug
mkdir -p build/release
cmake -B build/debug -S . -D CMAKE_BUILD_TYPE=Debug
cmake -B build/release -S . -D CMAKE_BUILD_TYPE=Release
cmake --build build/debug
cmake --build build/release

alg=( rec rec_cache tailrec iterative iterative_cache unroll )
alg_wo_rec=( rec_cache tailrec iterative iterative_cache unroll )

# Create objdump files
echo "Creating objdump files"
for f in "${alg[@]}"
do
    objdump -d --source build/debug/CMakeFiles/libfib_$f.dir/src/fib_$f.c.o > build/debug/fib_$f.objdump
    objdump -d --source build/release/CMakeFiles/libfib_$f.dir/src/fib_$f.c.o > build/release/fib_$f.objdump
done

# Create risc files and objdumps
if [ -f ~/risc-compiler/bin/riscv64-unknown-elf-gcc ]; then
    echo "Compiling for RISC"
    for f in "${alg[@]}"
    do
        ~/risc-compiler/bin/riscv64-unknown-elf-gcc -O0 -g -c src/fib_$f.c -o build/debug/fib_$f.risc.o
        ~/risc-compiler/bin/riscv64-unknown-elf-gcc -O3 -g -c src/fib_$f.c -o build/release/fib_$f.risc.o

        ~/risc-compiler/bin/riscv64-unknown-elf-objdump -d --source build/debug/fib_$f.risc.o > build/debug/fib_$f.risc.objdump
        ~/risc-compiler/bin/riscv64-unknown-elf-objdump -d --source build/release/fib_$f.risc.o > build/release/fib_$f.risc.objdump
    done
fi
