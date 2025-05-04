//
// Created by perepilka on 5/4/25.
//

#ifndef TIMER_H
#define TIMER_H

#include <chrono>


class Timer {
    std::chrono::high_resolution_clock::time_point start_time;

public:
    void timer_start() {
        start_time = std::chrono::high_resolution_clock::now();
    }

    double timer_stop() {
        auto end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<double, std::milli>(end - start_time).count();
    }
};

#endif //TIMER_H
