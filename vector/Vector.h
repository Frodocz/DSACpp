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

#ifndef DSACPP_VECTOR_H
#define DSACPP_VECTOR_H

using Rank = int; // Rank
#define DEFAULT_CAPACITY 3 // default initial capacity（can be configured bigger in practice）

template <typename T>
class Vector {
protected:
    Rank _size; int _capacity; T *_elem; // size, capacity, and data space
    void copyFrom(const T *A, Rank lo, Rank hi); // copy from data of interval A[lo, hi)
    void expand(); // expand when capacity not enough
    void shrink(); // shrink the capacity when load factor is too small
    void bubbleSort(Rank lo, Rank hi); // scan and swap bubble sort algorithm (basic version)
    void bubbleSortEarlyStop(Rank lo, Rank hi); // scan and swap bubble sort algorithm (early stop)
    void bubbleSortJump(Rank lo, Rank hi); // scan and swap bubble sort algorithm (jump version)
    Rank maxItem(Rank lo, Rank hi); // find largest element in the vector
    void selectionSort(Rank lo, Rank hi); // selection sort algorithm
    void insertionSort(Rank lo, Rank hi); // insertion sort algorithm
    void merge(Rank lo, Rank mi, Rank hi); // merge algorithm, [lo, mi) and [mi, hi) to be sorted，lo < mi < hi
    void mergeSort(Rank lo, Rank hi); // merge sort algorithm
    Rank partition(Rank lo, Rank hi); // construct pivot algorithm
    void quickSort(Rank lo, Rank hi); // quick sort algorithm
public:
    /* Constructors */
    // Initialize vector with Capacity c, size s (pre-cond: s <= c) and initial value v
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) {
        _elem = new T[_capacity = c];
        for (_size = 0; _size < s; _elem[_size++] = v);
    }
    Vector(const T *A, int n) { copyFrom(A, 0, n); } // Copy the whole array A
    Vector(const T *A, Rank lo, Rank hi) { copyFrom(A, lo, hi); } // Copy array A of range [lo, hi)
    Vector(const Vector<T> &V) { copyFrom(V._elem, 0, V._size); } // Copy the whole vector V
    Vector(const Vector<T> &V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); } // Copy the whole vector V of range [lo, hi)
    /* Destructors */
    ~Vector() { delete [] _elem; } // free internal memory space
    /* Read-only Methods */
    Rank size() const { return _size; }
    bool empty() const { return !_size; }
    Rank find(const T &e) const { return find(e, 0, _size); } // find e in unsorted vector
    Rank find(const T &e, Rank lo, Rank hi) const { return find(e, lo, hi); } // find e in unsorted vector interval v[lo, hi)
    Rank search(const T &e) const { return (0 >= _size) ? -1 : search(e, 0, _size); } // binary search in sorted vector, rightmost
    Rank search(const T &e, Rank lo, Rank hi) const; // search in sorted vector interval v[lo, hi)
    /* Writable Methods */
    T& operator[] (Rank r); // override operator [], find reference of element by rank
    const T& operator[] (Rank r) const; // restricted to be used as rvalue only
    Vector<T>& operator= (const Vector<T> &V); // override = to deep copy vector V
    T remove(Rank r); // remove the element at rank r
    int remove(Rank lo, Rank hi); // remove the elements at interval [lo, hi)
    Rank insert(Rank r, const T &e); // insert an element e at rank r
    Rank insert(const T &e) { return insert(_size, e); } // by default, insert as the last element
    void sort(Rank lo, Rank hi); // sort the interval [lo, hi)
    void sort() { sort(0, _size); } // sort the whole vector
    void shuffle(Rank lo, Rank hi); // uniformly unsort interval [lo, hi)
    void shuffle() { shuffle(0, _size); } // unsort the whole vector
    int deduplicate(); // remove duplicates in unsorted vector
    int uniquify(); // remove duplicates in sorted vector
    /* Traversal */
    void traverse ( void (* ) ( T& ) ); // Traversal using function pointer (Read-only or locally modification)
    template <typename VST> void traverse ( VST& ); // Traversal using function object (globally modification)
};

#include "Vector_Implementation.h"

#endif //DSACPP_VECTOR_H
