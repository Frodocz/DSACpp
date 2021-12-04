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

#ifndef DSACPP_VECTOR_SORT_H
#define DSACPP_VECTOR_SORT_H

template<typename T>
void Vector<T>::sort(Rank lo, Rank hi) { // sort vector range [lo, hi)
    switch (rand() % 5) {
        case 1: bubbleSort(lo, hi); break;
        case 2: bubbleSortEarlyStop(lo, hi); break;
        case 3: bubbleSortJump(lo, hi); break;
        case 4: selectionSort(lo, hi); break;
        case 5: insertionSort(lo, hi); break;
        default: insertionSort(lo, hi); break;
    }
}

#endif //DSACPP_VECTOR_SORT_H
