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
#ifndef DSACPP_VECTOR_INSERTION_SORT_H
#define DSACPP_VECTOR_INSERTION_SORT_H

template<typename T> // insertion sort algorithm
void Vector<T>::insertionSort(Rank lo, Rank hi) { // assert: 0 <= lo < hi <= size
    for (Rank i = lo + 1; i < hi; ++i) {
        T next = _elem[i]; // next element to insert
        Rank j;
        for (j = i - 1; j >= 0 && _elem[j] > next; --j) {
            _elem[j + 1] = _elem[j];
        }
        _elem[j + 1] = next;
    }
}

#endif //DSACPP_VECTOR_INSERTION_SORT_H
