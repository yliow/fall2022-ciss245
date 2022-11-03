#include <iostream>
#include "IntDynArray.h" // reimplementation of std::vector

int main()
{
    IntDynArray a(5); // a models an array of cap 5, size 0
    a.resize(3);
    std::cout << "a: " << a << '\n';
    return 0;
}
