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

#ifndef DSACPP_VECTOR_SEARCH_BINARY_H
#define DSACPP_VECTOR_SEARCH_BINARY_H

template<typename T>
Rank Vector<T>::search(const T &e, Rank lo, Rank hi) const {
    return binSearchC(_elem, e, lo, hi);
}

// binary search (version A): in sorted vector region [lo, hi), find element e (0 <= lo <= hi <= _size)
template<typename T>
static Rank binSearchA(T *S, const T &e, Rank lo, Rank hi) {
    while (lo < hi) { // every step two comparisons, three branches; early stop when found
        Rank mi = (lo + hi) >> 1; // pivot at mid point
        if      (e < S[mi]) hi = mi; // go to [lo, mi)
        else if (S[mi] < e) lo = mi + 1; // go to [mi + 1, hi)
        else                return mi; // find at mi
    }
    return -1; // failed to find e
} // when multiple e exist, cannot guarantee the rightmost is returned; when failed, cannot indicate the last failed index

// binary search (version B): in sorted vector region [lo, hi), find element e (0 <= lo <= hi <= _size)
template<typename T>
static Rank binSearchB(T *S, const T &e, Rank lo, Rank hi) {
    while (1 < hi - lo) { // every step only one comparisons, two branches; cannot early stop when found
        Rank mi = (lo + hi) >> 1; // pivot at mid point
        (e < S[mi]) ? hi = mi : lo = mi; // go to [lo, mi) or [mi, hi)
    } // when exit, hi = lo + 1，only one element A[lo]
    return e < S[lo] ? lo - 1 : lo; // return the biggest element that <= e
}

// binary search (version C): in sorted vector region [lo, hi), find element e (0 <= lo <= hi <= _size)
template<typename T>
static Rank binSearchC(T *S, const T &e, Rank lo, Rank hi) {
    while (lo < hi) { // every step only one comparisons, two branches; cannot early stop when found
        Rank mi = (lo + hi) >> 1; // pivot at mid point
        (e < S[mi]) ? hi = mi : lo = mi + 1; // go to [lo, mi) or (mi, hi)
    } // when exit, lo is the min rank of element > e, so lo - 1 is the max Rank of element <= e
    return lo - 1; // return the biggest element that <= e
} // when multiple e exist, guarantee the rightmost one is returned; when failed, indicate the last failed index

#endif //DSACPP_VECTOR_SEARCH_BINARY_H
