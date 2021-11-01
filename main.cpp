#include <iostream>
#include "vector/Vector.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Vector<int> v(5, 2, 3);
    std::cout << v.size() << std::endl;
    return 0;
}
