#include "lz4.hpp"
#include "../lz4/lz4.h"

namespace lz4 {

int compress(const char * src, char * dst, int src_size, int dst_size, int compression_level) {
    return LZ4_compress_fast(src, dst, src_size, dst_size, LZ4_ACCELERATION_MAX - compression_level + 1);
}
int decompress(const char * src, char * dst, int compressed_size, int dst_size) {
    return LZ4_decompress_safe(src, dst, compressed_size, dst_size);
}

}
