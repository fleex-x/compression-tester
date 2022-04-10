#pragma once

#include <chrono>

struct OneShotTimer
{
    void begin() {
        begin_ = timer_.now();
    }

    void end() {
        end_ = timer_.now();
    }

    auto ns() const {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(end_ - begin_);
    }

    auto s() const {
        return std::chrono::duration_cast<std::chrono::seconds>(end_ - begin_);
    }

    auto mics() const {
        return std::chrono::duration_cast<std::chrono::microseconds>(end_ - begin_);
    }

private:
    std::chrono::time_point<std::chrono::steady_clock> begin_;
    std::chrono::time_point<std::chrono::steady_clock> end_;
    std::chrono::steady_clock timer_;
};