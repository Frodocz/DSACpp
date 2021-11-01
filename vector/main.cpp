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
//    srand ((unsigned int) time(NULL));
//    testVector<int> (atoi(argv[1]));
    return 0;
}