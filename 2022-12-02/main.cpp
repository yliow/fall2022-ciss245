#include <iostream>

int sum_iter(int n)
{
    int s = 0;
    for (int i = 0; i <= n; ++i)
    {
        s = s + i;
    }
    return s;
}

int sum(int n)
{
    if (n == 0)
    {
        std::cout << "sum ... n = 0 ... base\n";
        return 0;
    }
    else
    {
        std::cout << "sum ... n = " << n << " ... recursive case\n";
        int ret = sum(n - 1);
        std::cout << "sum ... n = " << n << " received " << ret
                  << " ... returning " << ret + n << '\n';
        return ret + n;
    }
}

int main()
{
    std::cout << sum(5) << '\n';
    //std::cout << sum_iter(5) << '\n';
    return 0;
}
