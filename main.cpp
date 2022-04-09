#include "lz4/lz4.h"

#include <iostream>
#include <cstring>

const int N = 100500;

const char * in;
char out[N];
char out2[N];

int main() {
    in = "baaaaaaaaaaaaaaaaaaaaabbaaaaaaalolaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    int s = LZ4_compress_fast(in, out, strlen(in), 1000, 2);
    char * ptr = out;
    int cnt = 0;
    while (*ptr != 0 || cnt < 10) {
        printf("%d\n", (int)*ptr);
        ++ptr;
        ++cnt;
    }

    LZ4_decompress_safe(out, out2, s, N);
    printf("decomp: %s\n", out2);

}