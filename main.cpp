#include <iostream>
#include <cstring>

#include "wrapper/zstd.hpp"
#include "wrapper/lz4.hpp"

#include "bench/core.hpp"

#include <ostream>

std::ostream &operator<<(std::ostream &os, const Stat &stat)
{
    os << "Verified: " << std::boolalpha << stat.verified << "\n";
    os << "Input size(mb): " << (double)stat.src_size / (1.0 * 1024 * 1024) << "\n";
    os << "Compressed size(mb): " << (double)stat.compressed_size / (1.0 * 1024 * 1024) << "\n";
    os << "Compressed time(sec): " << stat.duration_comp_mics.count() / 1e6 << "\n";
    os << "Decompressed time(sec): " << stat.duration_decomp_mics.count() / 1e6 << "\n";

    return os;
}

int main()
{

    auto s = measure("source/mozilla", zstd::compress, zstd::decompress, 1);
    std::cout << "=== ZSTD ===\n"
              << s;

    s = measure("source/mozilla", lz4::compress, lz4::decompress, LZ4_COMPRESS_MAX);
    std::cout << "=== LZ4 ===\n"
              << s;
}