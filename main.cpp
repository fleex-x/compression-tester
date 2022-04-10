#include <iostream>
#include <cstring>

#include "wrapper/zstd.hpp"
#include "wrapper/lz4.hpp"

#include "bench/core.hpp"

#include <ostream>
#include <vector>
#include <string>

std::ostream &operator<<(std::ostream &os, const Stat &stat)
{
    os << "Verified: " << std::boolalpha << stat.verified << "\n";
    os << "Input size(mb): " << (double)stat.src_size / (1.0 * 1024 * 1024) << "\n";
    os << "Compressed size(mb): " << (double)stat.compressed_size / (1.0 * 1024 * 1024) << "\n";
    os << "Compressed time(sec): " << stat.duration_comp_mics.count() / 1e6 << "\n";
    os << "Decompressed time(sec): " << stat.duration_decomp_mics.count() / 1e6 << "\n";

    return os;
}

std::vector<std::string> test_files =
  {
      "dickens"
    , "mozilla"
    , "mr"
    , "nci"
    , "ooffice"
    , "osdb"
    , "reymont"
    , "samba"
    , "sao"
    , "webster"
    , "xml"
    , "x-ray"
  };

void run_tests() {
    for (auto file_name : test_files) {
        std::cout << "testing " << file_name << "..." << std::endl;

        auto s =  measure("source/" + file_name, zstd::compress, zstd::decompress, 1);
        std::cout << "=== ZSTD COMPRESSION LEVEL MIN ===\n"
              << s;

        s =  measure("source/" + file_name, zstd::compress, zstd::decompress, 7);
        std::cout << "=== ZSTD COMPRESSION LEVEL MAX ===\n"
              << s;

        s =  measure("source/" + file_name, lz4::compress, lz4::decompress, LZ4_COMPRESS_MAX);
        std::cout << "===  LZ4 COMPRESSION LEVEL MAX ===\n"
              << s;

        std::cout << std::endl << std::endl;
    }
}


int main()
{

    run_tests();
}
