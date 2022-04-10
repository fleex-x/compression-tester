#pragma once 
#include <chrono>
#include <string>

using CompressFunc = int (*) (const char * src, char * dst, int src_size, int dst_size, int compression_level);
using DecompressFunc = int (*) (const char * src, char * dst, int src_size, int dst_size);


// assume file size < 4GiB
struct Stat {
    std::chrono::microseconds duration_comp_mics;
    std::chrono::microseconds duration_decomp_mics;
    int src_size;
    int compressed_size;
    bool verified;
};

Stat measure(std::string fname, CompressFunc compress, DecompressFunc decompress, int compr_level);