#include <iostream>

// SquareFunction.h
class SquareFunction
{
public:
    SquareFunction()
        : previous_x(0), previous_y(0)
    {}
    int operator()(int);
private:
    int previous_x;
    int previous_y; // result
};

// SquareFunction.cpp
int SquareFunction::operator()(int x)
{
    if (previous_x == x)
    {
        std::cout << "no recomputation!\n";
        return previous_y;
    }
    else
    {
        std::cout << "too bad compute!\n";
        previous_x = x;
        previous_y = x * x;
        return previous_y;
    }
}


int simplesquare(int x)
{
    return x * x;
}

int fib(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int fib2(int n)
{
    int t[n + 1] = {1, 1};
    // int * t = new int[n + 1];
    for (int i = 2; i <= n; ++i)
    {
        t[i] = t[i - 1] + t[i - 2];
    }
    return t[n];
}

class Fib
{
public:
    Fib()
        : completed(2)
    {
        t[0] = t[1] = 1;
    }
    int operator()(int n)
    {
        if (n < completed)
        {
            return right away
        }
        
    }
    int t[1000];
    int completed;
};

int main()
{
    // SquareFunction square;
    // std::cout << square(3) << '\n';
    // std::cout << square(3) << '\n';
    // std::cout << square(3) << '\n';
    // std::cout << square(4) << '\n';
    // std::cout << square(4) << '\n';

    for (int n = 0; n <= 50; ++n)
    {
        std::cout << "fib2(" << n << ") = "
                  << fib2(n) << '\n';
    }
    Fib()(0)
    return 0;
}

