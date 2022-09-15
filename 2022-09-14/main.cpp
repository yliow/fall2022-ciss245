#include <iostream>
#include "mymath.h"

int main()
{
    std::cout << square(5) << '\n';

    return 0;
}

int square(int x)
{
    return x * x;
}

