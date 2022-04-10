cmake_minimum_required(VERSION 3.0)

project(compression-tester)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB zstd_common "zstd/common/*.h" "zstd/common/*.c")
file(GLOB zstd_compress "zstd/compress/*.h" "zstd/compress/*.c")
file(GLOB zstd_decompress "zstd/decompress/*.h" "zstd/decompress/*.c" "zstd/decompress/*.S")
file(GLOB zstd_dict_builder "zstd/dictBuilder/*.h" "zstd/dictBuilder/*.c")

set(zstd ${zstd_common} ${zstd_compress} ${zstd_decompress} ${zstd_dict_builder})
file(GLOB lz4 "lz4/*.h" "lz4/*.c")

file(GLOB bench "bench/*.hpp" "bench/*.cpp")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic") # TODO add -Werror

add_executable(main main.cpp ${lz4} ${zstd} ${bench} zstd/zstd.h)