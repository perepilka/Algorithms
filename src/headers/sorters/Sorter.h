//
// Created by perepilka on 5/3/25.
//

#ifndef SORTER_H
#define SORTER_H

#include <vector>
#include "InsertionSort.h"
#include "BinaryInsertionSort.h"
#include "QuickSort.h"
#include "HeapSort.h"

enum class SortType {
    InsertionSort,
    BinaryInsertionSort,
    QuickSort,
    HeapSort,
};

template<typename Type>
class Sorter {
public:
    static void sort(std::vector<Type> &vec, SortType sortType) {
        switch (sortType) {
            case SortType::InsertionSort:
                InsertionSort::insertionSort(vec);
                break;
            case SortType::BinaryInsertionSort:
                BinaryInsertionSort::binaryInsertionSort(vec);
            case SortType::QuickSort:
                QuickSort::quicksort(vec);
                break;
            case SortType::HeapSort:
                HeapSort::heapSort(vec);
            default:
                return;
        }
    }
};


#endif //SORTER_H
