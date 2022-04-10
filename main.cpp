#include "lz4/lz4.h"
#include "zstd/zstd.h"

#include <iostream>
#include <cstring>

const int N = 100500;

const char * in;
char out[N];
char out2[N];

ZSTDLIB_API size_t ZSTD_compress( void* dst, size_t dstCapacity,
                            const void* src, size_t srcSize,
                                  int compressionLevel);

ZSTDLIB_API size_t ZSTD_decompress( void* dst, size_t dstCapacity,
                              const void* src, size_t compressedSize);

int main() {
    in = "baaaaaaaaaaaaaaaaaaaaabbaaaaaaalolaaa";
    int s = LZ4_compress_fast(in, out, strlen(in), 1000, 2);
    char * ptr = out;
    int cnt = 0;
    while (*ptr != 0 || cnt < 10) {
        printf("%d\n", (int)*ptr);
        ++ptr;
        ++cnt;
    }

    LZ4_decompress_safe(out, out2, s, N); // works wrong!! extra "aa" at the end
    printf("decomp: %s\n", out2);

    puts("==== TESTING ZSTD ====");

    s = ZSTD_compress(out, N, in, strlen(in), 2);
    ZSTD_decompress(out2, N, out, s);

    printf("Result: %s\n", out2);


}