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

#ifndef DSACPP_VECTOR_OPERATORS_H
#define DSACPP_VECTOR_OPERATORS_H

template<typename T>
T& Vector<T>::operator[](Rank r) {
    return _elem[r]; // assert: 0 <= r < _size
}

template<typename T>
const T& Vector<T>::operator[](Rank r) const { // rValue only
    return _elem[r]; // assert: 0 <= r < _size
}

#endif //DSACPP_VECTOR_OPERATORS_H
