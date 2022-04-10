#pragma once

namespace lz4 {

int compress(const char * src, char * dst, int src_size, int dst_size, int compression_level);
int decompress(const char * src, char * dst, int compressed_size, int dst_size);

}
