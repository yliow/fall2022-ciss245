#include <iostream>

int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return sum(n - 1) + n;
    }
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return factorial(n - 1) * n;
    }
}




int main()
{
    std::cout << (sum(3) == 6 ? "pass" : "FAIL") << '\n';
    std::cout << (sum(4) == 10 ? "pass" : "FAIL") << '\n';
    return 0;
}
