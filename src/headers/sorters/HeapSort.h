//
// Created by perepilka on 5/3/25.
//

#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>

class HeapSort {
private:
    /**
  * Internal method for heapsort.
  * i is the index of an item in the heap.
  * Returns the index of the left child.
  */
    static inline int leftChild(int i) {
        return 2 * i + 1;
    }


    /**
     * Internal method for heapsort that is used in deleteMax and buildHeap.
     * i is the position from which to percolate down.
     * n is the logical size of the binary heap.
     */
    template<typename Type>
    static void percDown(std::vector<Type> &vec, int i, int n) {
        int child;
        Type tmp;

        for (tmp = std::move(vec[i]); leftChild(i) < n; i = child) {
            child = leftChild(i);
            if (child != n - 1 && vec[child] < vec[child + 1])
                ++child;
            if (tmp < vec[child])
                vec[i] = std::move(vec[child]);
            else
                break;
        }
        vec[i] = std::move(tmp);
    }

public:
    /**
  * Standard heapsort.
  */
    template<typename Type>
    static void heapSort(std::vector<Type> &vec) {
        for (int i = vec.size() / 2 - 1; i >= 0; --i) /* buildHeap */
            percDown(vec, i, vec.size());
        for (int j = vec.size() - 1; j > 0; --j) {
            std::swap(vec[0], vec[j]); /* deleteMax */
            percDown(vec, 0, j);
        }
    }
};

#endif //HEAPSORT_H
