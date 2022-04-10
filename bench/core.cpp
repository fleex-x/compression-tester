#include "core.hpp"
#include "fileholder.hpp"
#include "timer.hpp"
#include <iostream>

Stat measure(std::string fname, CompressFunc compress, DecompressFunc decompress)
{
    try
    {
        FileHolder fh(std::move(fname));
    }
    catch (std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
        return {{}, {}, {}, false};
    }



}