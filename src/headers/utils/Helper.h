//
// Created by perepilka on 5/3/25.
//

#ifndef HELPER_H
#define HELPER_H

#include <vector>
#include <sorters/Sorter.h>
#include <fstream>
#include <cstdlib>


class Helper {
public:
    template<typename Type>
    static void print_vec(std::vector<Type> &vec) {
        for (auto i: vec) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }


    static void sort(std::vector<int> &int_vec, std::vector<float> &float_vec, std::vector<char> &char_vec,
                     SortType sort_type, DataType
                     data_type) {
        switch (data_type) {
            case DataType::INT:
                Sorter<int>::sort_menu(int_vec, sort_type);
                break;
            case DataType::FLOAT:
                Sorter<float>::sort_menu(float_vec, sort_type);
                break;
            case DataType::CHAR:
                Sorter<char>::sort_menu(char_vec, sort_type);
                break;
        }
    }


    static void checkPath(const std::string &filepath) {
        std::ofstream file(filepath);
        if (!file.is_open()) {
            std::cerr << "Nie udalo sie otworzyc plik '" << filepath << "'." << std::endl;
            exit(EXIT_FAILURE);
        }
        file.close();
        std::remove(filepath.c_str());
    }


    static void saveRes(const std::string &filepath, double value) {
        std::ofstream file(filepath);

        file << value;
        file.close();
    }
    static double calculateAverageResult(const std::vector<double>& vec) {
        if (vec.empty()) return 0.0;

        double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
        return sum / vec.size();
    }
};




#endif //HELPER_H
