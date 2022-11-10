#include <iostream>
#include "C.h"

int main()
{
    C c(42);
    std::cout << c.i << ' ' << c.j << ' ' << C::j << '\n';

    C d(99);
    std::cout << d.i << ' ' << d.j << ' ' << C::j << '\n';

    c.j = -1;
    std::cout << c.j << ' ' << d.j << '\n';
    std::cout << &(c.j) << ' ' << &(d.j) << '\n';

    C::increment_j();
    std::cout << C::j << '\n';
    return 0;
}
