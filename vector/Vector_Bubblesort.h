/*******************************************************************************
 * Data Structures and Algorithms C++ IMPLEMENTATIONS
 *
 * Vector: A sequence container representing arrays that can change in size.
 *
 * https://en.wikipedia.org/wiki/Vector#Computer_science
 *
 * @author ZHANG Chao (frodocz1226@gmail.com)
 * @github Frodocz
 *
 ******************************************************************************/

#ifndef DSACPP_VECTOR_BUBBLE_SORT_H
#define DSACPP_VECTOR_BUBBLE_SORT_H

template<typename T> // Sort the Vector range [lo, hi) basic version
void Vector<T>::bubbleSort(Rank lo, Rank hi) { //assert: 0 <= lo < hi <= size
    while (lo < --hi) {
        for (Rank i = lo; i < hi; ++i)
            if (_elem[i] > _elem[i + 1]) // swap the reversed-order pair
                swap(_elem[i], _elem[i + 1]);
    }
}

template<typename T> // Sort the Vector range [lo, hi) early stop version
void Vector<T>::bubbleSortEarlyStop(Rank lo, Rank hi) { //assert: 0 <= lo < hi <= size
    while (lo < --hi) {
        bool sorted = true;
        for (Rank i = lo; i < hi; ++i) {
            if (_elem[i] > _elem[i + 1])
                swap(_elem[i], _elem[i + 1]), sorted = false;
        }
        if (sorted) return;
    }
}

template<typename T> // Sort the Vector range [lo, hi) jump version
void Vector<T>::bubbleSortJump(Rank lo, Rank hi) { //assert: 0 <= lo < hi <= size
    for (Rank last = --hi; lo < hi; hi = last) {
        for (Rank i = last = lo; i < hi; ++i) {
            if (_elem[i] > _elem[i + 1]) {
                swap(_elem[last = i], _elem[i + 1]);
            }
        }
    }
}

#endif //DSACPP_VECTOR_BUBBLE_SORT_H
