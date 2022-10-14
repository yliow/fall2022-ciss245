#include <iostream>
#include "Array.h"

int main()
{
    Array a;       // have a.x int array x of size 5, size. 
    Array_init(a); // a.size set to 0
    std::cout << a << '\n'; // print {}
    Array_pushback(a, 2);
    std::cout << a << '\n'; // print {2}
    Array_pushback(a, 42);
    std::cout << a << '\n'; // print {2, 42}
    Array_pushback(a, 3);
    std::cout << a << '\n'; // print {2, 42, 3}
    Array_pushback(a, -1);
    std::cout << a << '\n'; // print {2, 42, 3}
    Array_pushback(a, 0);
    std::cout << a << '\n'; // print {2, 42, 3}
    Array_pushback(a, 99);
    std::cout << a << '\n'; // print {2, 42, 3}
    Array_popback(a);
    std::cout << a << '\n'; // print {2, 42, 3}

    return 0;
}
