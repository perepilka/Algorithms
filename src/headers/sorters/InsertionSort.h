//
// Created by perepilka on 5/3/25.
//

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <vector>

class InsertionSort {
public:
    template<typename Type>
    static void insertionSort(std::vector<Type> &a) {
        for (int p = 1; p < a.size(); ++p) {
            Type tmp = std::move(a[p]);

            int j;
            for (j = p; j > 0 && tmp < a[j - 1]; --j)
                a[j] = std::move(a[j - 1]);
            a[j] = std::move(tmp);
        }
    }
};

#endif //INSERTIONSORT_H
