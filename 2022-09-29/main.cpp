#include <iostream>
#include <cmath>

bool isprime(int n)
{
    if (n < 2) return false;
    for (int d = 2; d <= sqrt(n); ++d)
    {
        if (n % d == 0) return false;
    }
    return true;
}

void nextprime(int & y)
{
    while (1)
    {
        ++y;
        std::cout << "trying " << y << '\n'; 
        if (isprime(y)) return;
    }
}
void nextprime(int * p)
{
    while (1)
    {
        ++(*p);
        std::cout << "trying " << (*p) << '\n'; 
        if (isprime(*p)) return;
    }
}

int main()
{
    int x = 0;
    for (int i = 0; i < 5; ++i)
    {
        nextprime(x);
        std::cout << x << '\n';
    }
    std::cout << '\n';
    for (int i = 0; i < 5; ++i)
    {
        nextprime(&x);
        std::cout << x << '\n';
    }

    return 0;
}
