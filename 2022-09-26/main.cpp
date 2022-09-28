#include <iostream>

void f(int * p)
{
    *p = 0;
}

int main()
{
    int x = 42;
    f(&x); // f changes x to 0
    std::cout << x << '\n';
    return 0;
}
