#include <iostream>
#include <ctime>
#include <cstdlib>

int num_digits(int n);


int main()
{
    srand((unsigned int) time(NULL));
    for (int i = 0; i < 10; ++i)
    {
        int r = rand();
        std::cout << r << '\n';
    }
    std::cout << RAND_MAX << '\n';
    
    // int n;
    // std::cin >> n;
    // std::cout << num_digits(n) << '\n';
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

