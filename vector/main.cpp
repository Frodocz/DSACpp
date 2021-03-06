/*******************************************************************************
 * Data Structures and Algorithms C++ IMPLEMENTATIONS
 *
 * Vector: A sequence container representing arrays that can change in size.
 * Testing Vector functionalities
 *
 * https://en.wikipedia.org/wiki/Vector#Computer_science
 *
 * @author ZHANG Chao (frodocz1226@gmail.com)
 * @github Frodocz
 *
 ******************************************************************************/
#include<iostream>
using namespace std;

#include "Vector.h"

int main(int argc, char* argv[]) {
    cout << "Testing Vector" << endl;
    Vector<int> v(10, 3, 2);
    cout << v.size() << endl;

    int A[10] = {1, 2, 9, 6, 22, -8, 993, 12, 22, 6};
    Vector<int> v2(A, 10);
    v2.sort();

    for (auto i = 0; i < v2.size(); ++i)
        cout << v2[i] << " ";
    return 0;
}