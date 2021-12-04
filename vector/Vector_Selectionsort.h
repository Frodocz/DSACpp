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

#ifndef DSACPP_VECTOR_SELECTION_SORT_H
#define DSACPP_VECTOR_SELECTION_SORT_H

template<typename T> // find largest element in [lo, hi)
Rank Vector<T>::maxItem(Rank lo, Rank hi) {
    T maxRank = hi;
    while (lo < hi--) { // scan from back
        if (_elem[hi] > _elem[maxRank])
            maxRank = hi; // guarantee selectionSort stable (elements of same value, the rightmost one highest priority)
    }
    return maxRank;
}

template<typename T> // selection sort algorithm
void Vector<T>::selectionSort(Rank lo, Rank hi) { // assert: 0 <= lo < hi <= size
    while (lo < --hi) {
        swap(_elem[maxItem(lo, hi)], _elem[hi]);
    }
}

#endif //DSACPP_VECTOR_SELECTION_SORT_H
