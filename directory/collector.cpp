#include <string>
#include "../bench/core.hpp"
#include "json.hpp"
#include <iostream>

class JsonBuilder {
private:
    nlohmann::json file;
    enum {
        EMPTY,
        TIME,
        COMP
    } type;

public:
    void addTimeInfo(const Stat &stat, std::string &funcName, std::string sourceName, int level) {
        if (stat.verified) {
            std::cerr << "Non-verified compression" << std::endl;
        }
        if (type == EMPTY || type == TIME) {
            file[sourceName] = {{"func-name",   funcName},
                                {"comp-level",  level},
                                {"comp-time",   std::to_string(stat.duration_comp_mics.count())},
                                {"decomp-time", std::to_string(stat.duration_decomp_mics.count())}};
            type = TIME;
        } else {
            std::cerr << "Wrong json object";
        }
    }


    void addCompInfo(const Stat &stat, std::string &funcName, std::string sourceName, int level) {
        if (stat.verified) {
            std::cerr << "Non-verified compression" << std::endl;
        }
        if (type == EMPTY || type == COMP) {
            file[sourceName] = {{"func-name",  funcName},
                                {"comp-level", level},
                                {"orig-size",  std::to_string(stat.src_size)},
                                {"comp-size",  std::to_string(stat.compressed_size)}};
            type = COMP;
        } else {
            std::cerr << "Wrong json object";
        }
    }

    nlohmann::json get() {
        return file;
    }
};