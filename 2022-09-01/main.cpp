#include <iostream>

int num_digits(int n);


int main()
{
    int n;
    std::cin >> n;
    std::cout << num_digits(n) << '\n';
    return 0;
}

int num_digits(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        int count = 0;
        while (n != 0)
        {
            //int digit = n % 10;
            //std::cout << digit << '\n';
            n /= 10;
            ++count;
        }
        return count;
    }
}
