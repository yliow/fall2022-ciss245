#include <iostream>
#include "IntDynArray.h" // reimplementation of std::vector

int main()
{
    IntDynArray a(5); // a models an array of cap 5, size 0
    a.resize(3);
    std::cout << "a: " << a << '\n';
    std::cout << "a[0]: " << a[0] << '\n';
    a[0] = 42;
    std::cout << "a[0]: " << a[0] << '\n';
    std::cout << "a: " << a << '\n';
    a[2] = 99;
    std::cout << "a[2]: " << a[2] << '\n';
    std::cout << "a: " << a << '\n';

    IntDynArray b(a);
    std::cout << "b: " << b << '\n';

    IntDynArray c(1000);
    c = a;
    std::cout << "c: " << c << '\n';

    c.resize(20);
    std::cout << "c: " << c << '\n';
        
    return 0;
}
