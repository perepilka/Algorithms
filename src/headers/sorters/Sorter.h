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
#include "utils/Timer.h"

enum class SortType {
    InsertionSort,
    BinaryInsertionSort,
    QuickSort,
    HeapSort,
};

template<typename Type>
class Sorter {
public:
    static void sort_menu(std::vector<Type> &vec, SortType sortType) {
        Timer timer;
        switch (sortType) {
            case SortType::InsertionSort:

                timer.timer_start();
                InsertionSort::insertionSort(vec);
                std::cout << "Insertion Sort: czas sortowania " << vec.size() << " elementow: " << std::to_string(
                    timer.timer_stop()) + "\n";

                break;
            case SortType::BinaryInsertionSort:

                timer.timer_start();
                BinaryInsertionSort::binaryInsertionSort(vec);
                std::cout << "Binary Insertion Sort: czas sortowania " << vec.size() << "elementow : " <<
                        std::to_string(
                            timer.timer_stop()) + "\n";
            case SortType::QuickSort:
                timer.timer_start();
                QuickSort::quicksort(vec);
                std::cout << "Quick Sort: czas sortowania " << vec.size() << "elementow : " << std::to_string(
                    timer.timer_stop()) + "\n";
                break;
            case SortType::HeapSort:
                timer.timer_start();
                HeapSort::heapSort(vec);
                std::cout << "Heap Sort: czas sortowania " << vec.size() << "elementow : " << std::to_string(
                    timer.timer_stop()) + "\n";
            default:
                return;
        }
    }

    static double sort(std::vector<Type> &vec, SortType sortType) {
        Timer timer;
        switch (sortType) {
            case SortType::InsertionSort:

                timer.timer_start();
            InsertionSort::insertionSort(vec);
            return timer.timer_stop() ;

            break;
            case SortType::BinaryInsertionSort:

                timer.timer_start();
            BinaryInsertionSort::binaryInsertionSort(vec);
            return timer.timer_stop() ;
            case SortType::QuickSort:
                timer.timer_start();
            QuickSort::quicksort(vec);
            return timer.timer_stop() ;
            break;
            case SortType::HeapSort:
                timer.timer_start();
            HeapSort::heapSort(vec);
            return timer.timer_stop() ;
            default:
                return 0.0;
        }
    }



};


#endif //SORTER_H
