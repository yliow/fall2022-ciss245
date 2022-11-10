#include <iostream>
#include "C.h"

int main()
{
    C c(42);
    std::cout << c.i << ' ' << c.j << ' ' << C::j << '\n';
    return 0;
}
