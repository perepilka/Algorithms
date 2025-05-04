//
// Created by perepilka on 5/3/25.
//

#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <vector>
#include <algorithm>

class QuickSort {
private:
    /**
     * Quicksort algorithm (driver).
     */
    template<typename Comparable>
    static void insertionSort(std::vector<Comparable> &vec, int left, int right) {
        for (int i = left + 1; i <= right; ++i) {
            Comparable tmp = std::move(vec[i]);
            int j = i;
            while (j > left && tmp < vec[j - 1]) {
                vec[j] = std::move(vec[j - 1]);
                --j;
            }
            vec[j] = std::move(tmp);
        }
    }

    /**
 * Return median of left, center, and right.
 * Order these and hide the pivot.
 */
    template<typename Comparable>
    static const Comparable &median3(std::vector<Comparable> &vec, int left, int right) {
        int center = (left + right) / 2;

        if (vec[center] < vec[left])
            std::swap(vec[left], vec[center]);
        if (vec[right] < vec[left])
            std::swap(vec[left], vec[right]);
        if (vec[right] < vec[center])
            std::swap(vec[center], vec[right]);

        // Place pivot at position right - 1
        std::swap(vec[center], vec[right - 1]);
        return vec[right - 1];
    }

    /**
     * Internal quicksort method that makes recursive calls.
     * Uses median-of-three partitioning and a cutoff of 10.
     * a is an array of Comparable items.
     * left is the left-most index of the subarray.
     * right is the right-most index of the subarray.
     */
    template<typename Comparable>
    static void quicksort(std::vector<Comparable> &vec, int left, int right) {
        const int CUTOFF = 10;

        if (left + CUTOFF <= right) {
            const Comparable &pivot = median3(vec, left, right);

            int i = left, j = right - 1;
            for (;;) {
                while (vec[++i] < pivot) {
                }
                while (pivot < vec[--j]) {
                }
                if (i < j)
                    std::swap(vec[i], vec[j]);
                else
                    break;
            }

            std::swap(vec[i], vec[right - 1]);

            quicksort(vec, left, i - 1);
            quicksort(vec, i + 1, right);
        } else {
            // insertionSort(vec, left, right);
            InsertionSort::insertionSort(vec);
        }
    }

public:
    /**
 * Insertion sort routine for subarrays.
 */
    template<typename Comparable>
    static void quicksort(std::vector<Comparable> &vec) {
        quicksort(vec, 0, vec.size() - 1);
    }
};


#endif //QUICKSORT_H
