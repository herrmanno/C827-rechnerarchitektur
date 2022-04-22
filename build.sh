cmake -B build/debug -S . -D CMAKE_BUILD_TYPE=Debug
cmake -B build/release -S . -D CMAKE_BUILD_TYPE=Release
cmake --build build/Debug
cmake --build build/Release
