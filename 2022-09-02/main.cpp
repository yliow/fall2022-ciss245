#include <iostream>
#include <cmath>

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
    for (int n = 1000000000; n < 2000000000; ++n)
    {
        std::cout << n << ' ' << isprime(n) << '\n';
    }
    return 0;
}
