#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

struct FileHolder
{
    FileHolder() = default;

    FileHolder(std::string fname) : storage_(), fname_(std::move(fname))
    {
        std::ifstream t(fname_);
        if (t.fail())
        {
            throw std::runtime_error("File does not exist");
        }
        t.seekg(0, std::ios::end);
        size_t size = t.tellg();
        storage_ = std::vector<char>(size);

        t.seekg(0);
        t.read(storage_.data(), size);

        t.close();
    }

    const char *data() const
    {
        return storage_.data();
    }

    std::size_t size() const
    {
        return storage_.size();
    }

private:
    std::vector<char> storage_;
    std::string fname_;
};