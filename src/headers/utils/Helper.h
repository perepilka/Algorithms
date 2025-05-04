//
// Created by perepilka on 5/3/25.
//

#ifndef HELPER_H
#define HELPER_H

#include <vector>
#include <filesystem>


class Helper {
    std::chrono::high_resolution_clock::time_point start_time;

public:
    template<typename Type>
    static void print_vec(std::vector<Type> &vec) {
        for (auto i: vec) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

     void timer_start() {
        start_time = std::chrono::high_resolution_clock::now();
    }
     double timer_stop() {
        auto end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<double, std::milli>(end - start_time).count();
    }


};



#endif //HELPER_H
