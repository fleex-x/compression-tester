#include "core.hpp"
#include "fileholder.hpp"
#include "timer.hpp"
#include <iostream>

Stat measure(std::string fname, CompressFunc compress, DecompressFunc decompress, int compr_level)
{
    FileHolder fh;
    try
    {
        fh = FileHolder(std::move(fname));
    }
    catch (std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
        return {{}, {}, {}, {}, false};
    }

    std::size_t size = fh.size();

    const float coef = 1.5f;
    std::vector<char> compressed(static_cast<std::size_t>(coef * size));

    // compr
    OneShotTimer timer_comp;
    timer_comp.begin();

    int comp_size = compress(fh.data(), compressed.data(), fh.size(), compressed.size(), compr_level);

    timer_comp.end();

    // decompr
    std::vector<char> decompressed(static_cast<std::size_t>(size));

    OneShotTimer timer_decomp;

    int decomp_size = decompress(compressed.data(), decompressed.data(), comp_size, size);

    timer_decomp.end();

    // verify

    bool ok = true;
    ok &= static_cast<std::size_t>(decomp_size) == size;
    if (ok) {
        for (std::size_t  i = 0; i < size; ++i) {
            ok &= decompressed[i] == fh.data()[i];
        }
    }

    return Stat{timer_comp.mics(), timer_decomp.mics(), static_cast<int>(size), comp_size, ok};
}