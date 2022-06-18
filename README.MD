# Case study for course 'C827 Rechnerarchitektur' of HTWK

This repository conatins multiple implementations of algorithms creating the Fibonacci sequence.

Slides to the corresponding case study can be found at [slides](./slides)

## Build

Compiling requires cmake. Creating additional artefacts requires `perf`, `objdump` and a RISC
toolchain.

### Configure

```
mkdir -p build/debug
mkdir -p build/release
cmake -B build/debug -S . -D CMAKE_BUILD_TYPE=Debug
cmake -B build/release -S . -D CMAKE_BUILD_TYPE=Release
```

### Compile to binary and object files

```
cmake --build build/debug
cmake --build build/release
```

### Configure, Compile and create further artefacts

```
bash build.sh
```

### Build on remote machine and download artifacts

```
bash build_remote.sh [ssh-connection-string]
```
