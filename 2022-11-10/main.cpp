#include <iostream>
#include "C.h"

int main()
{
    std::cout << "num:" << C::num_objects * sizeof(C) << '\n';
    C c0(42);
    std::cout << "num:" << C::num_objects * sizeof(C) << '\n';
    C c1(42);
    std::cout << "num:" << C::num_objects * sizeof(C) << '\n';
    C c2(42);
    std::cout << "num:" << C::num_objects * sizeof(C) << '\n';
    // C::num_objects = 3

    int x = 0;
    if (x == 0)
    {
        C c3(42);
        std::cout << "num:" << C::num_objects * sizeof(C) << '\n';
        C c4(42);
        std::cout << "num:" << C::num_objects * sizeof(C) << '\n';
    }
    std::cout << "num:" << C::num_objects * sizeof(C) << '\n';
        
    
    return 0;
}
