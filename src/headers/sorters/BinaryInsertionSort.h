//
// Created by perepilka on 5/3/25.
//

#ifndef BINARYINSERTIONSORT_H
#define BINARYINSERTIONSORT_H

#include <vector>

class BinaryInsertionSort {
private:
    template<typename Type>
    static int binarySearch(const std::vector<Type> &vec, const Type &key, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (vec[mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

public:
    template<typename Type>
    static void binaryInsertionSort(std::vector<Type> &vec) {
        for (size_t i = 1; i < vec.size(); ++i) {
            Type key = vec[i];

            int pos = binarySearch(vec, key, 0, i - 1);

            for (int j = i - 1; j >= pos; --j) {
                vec[j + 1] = vec[j];
            }
            vec[pos] = key;
        }
    }
};

#endif //BINARYINSERTIONSORT_H
