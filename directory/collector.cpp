#include <string>
#include "../bench/core.hpp"
#include "json.hpp"
#include <iostream>

class JsonBuilder {
private:
    nlohmann::json file;

public:
    void addInfo(const Stat &stat, const std::string &funcName, std::string &sourceName) {
        if (!stat.verified) {
            std::cerr << "Non-verified compression" << std::endl;
        }
        file[sourceName][funcName].push_back(
                {"comp-time", std::to_string((double) stat.duration_comp_mics.count() / 1e6)});
        file[sourceName][funcName].push_back(
                {"decomp-time", std::to_string((double) stat.duration_decomp_mics.count() / 1e6)});
        file[sourceName][funcName].push_back(
                {"orig-size", std::to_string((double) stat.src_size / (1.0 * 1024 * 1024))});
        file[sourceName][funcName].push_back({"comp-size", std::to_string(
                (double) stat.compressed_size / (1.0 * 1024 * 1024))});
    }

    nlohmann::json get() {
        auto ret_file = file;
        file.clear();
        return ret_file;
    }

};