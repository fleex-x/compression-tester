#pragma once

#define LZ4_ACCELERATION_DEFAULT 1 // defined in ../lz4/lz4.c
#define LZ4_ACCELERATION_MAX 65537 // defined in ../lz4/lz4.c

#define LZ4_COMPRESS_MIN 1 // defined in ../lz4/lz4.c
#define LZ4_COMPRESS_MAX 65537 // defined in ../lz4/lz4.c

namespace lz4 {

int compress(const char * src, char * dst, int src_size, int dst_size, int compression_level);
int decompress(const char * src, char * dst, int compressed_size, int dst_size);

}
