#include <iostream>
#include <cmath>

class ZeroDivError
{};

class SqrtOfNegError
{
public:
    SqrtOfNegError(int x)
        : x_(x)
    {}
    int x_;
};
std::ostream & operator<<(std::ostream & cout, const SqrtOfNegError & e)
{
    cout << "ERROR: sqrt(" << e.x_ << ") is attempted\n";
    return cout;
}

int f(int x, int y)
{
    if (x == y) throw ZeroDivError();
    if (x < 0) throw SqrtOfNegError(x);
        
    return (x + 1) / (x - y) + sqrt(x);
}

int g()
{
    try
    {
        std::cout << f(2, 1) << std::endl;
        //std::cout << f(2, 2) << std::endl;
        std::cout << f(-2, 2) << std::endl;
    }
    catch (ZeroDivError & e)
    {
        std::cout << "g is catcher\n";
        std::cout << "i caught a ZeroDivError ... etc\n";
    }
    
    return 0;
}

int main()
{
    try
    {
        g();
    }
    catch (SqrtOfNegError & e)
    {
        std::cout << "main is catcher\n";
        std::cout << "i caught a sqrt-of-neg-number error ... etc\n";
        std::cout << e << '\n';
    }
    return 0;
}
