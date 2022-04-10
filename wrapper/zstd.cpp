#include "zstd.hpp"
#include "../zstd/zstd.h"

namespace zstd {

int compress(const char * src, char * dst, int src_size, int dst_size, int compression_level) {
    return ZSTD_compress(dst, dst_size, src, src_size, compression_level);
}
int decompress(const char * src, char * dst, int compressed_size, int dst_size) {
    return ZSTD_decompress(dst, dst_size, src, compressed_size);
}

}
