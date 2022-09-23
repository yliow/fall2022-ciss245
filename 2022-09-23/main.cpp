#include <iostream>

int main()
{
    int x = 123;
    int y = 42;
    std::cout << "val of x:" << x << '\n'
              << "addr of x:" << (long long)(&x) << '\n';
    std::cout << "val of y:" << y << '\n'
              << "addr of y:" << (long long)(&y) << '\n';

    int z[3];
    for (int i = 0; i < 3; ++i)
    {
        std::cout << (long long)&(z[i]) << '\n';
    }


    int * p;
    p = &x;
    std::cout << "p:" << (long long)p << '\n';
    int * p1;
    p1 = p;
    std::cout << "p1:" << (long long)p1 << '\n';
    
    double d = 3.14, e = 2.718;
    double * q = &d;
    std::cout << d << ' ' << &d << '\n';
    std::cout << q << ' ' << &q << '\n';
    double ** r = &q;
    std::cout << r << '\n';

    
    return 0;
}





