#include <iostream>
#include <cmath>

int f(int x)
{
    std::cout << "x of f = " << x << '\n';
    x = 0;
    std::cout << "x of f = " << x << '\n';
    return 42;
}
int g(int & x)
{
    std::cout << "x of g = " << x << '\n';
    x = 0;
    std::cout << "x of g = " << x << '\n';
    return 42;
}

bool isprime(int n)
{
    if (n < 2)
    {
        return false;
    }
    else
    {
        for (int d = 2; d <= sqrt(n); ++d)
        {
            if (n % d == 0)
            {
                return false;
            }
        }
        return true;
    }
}
    
int main()
{
    // for (int n = 1000000000; n < 2000000000; ++n)
    // {
    //     std::cout << n << ' ' << isprime(n) << '\n';
    // }
    int x = 1;
    std::cout << "x of main = " << x << '\n';
    f(x);
    std::cout << "x of main = " << x << '\n';

    std::cout << "x of main = " << x << '\n';
    g(x);
    std::cout << "x of main = " << x << '\n';

    return 0;
}
