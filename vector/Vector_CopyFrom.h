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

#ifndef DSACPP_VECTOR_COPY_FROM_H
#define DSACPP_VECTOR_COPY_FROM_H

template<typename T>
void Vector<T>::copyFrom(T const *A, Rank lo, Rank hi) { // Copy vector from A[lo, hi) to _elem[0, hi - lo)
    _elem = new T[_capacity = 2 * (hi - lo)];
    for (_size = 0; lo < hi; ++_size, ++lo) {
        _elem[_size] = A[lo];
    }
}

#endif //DSACPP_VECTOR_COPY_FROM_H
