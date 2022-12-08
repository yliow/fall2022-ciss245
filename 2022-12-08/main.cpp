#include <iostream>

// max of values at addr start, start + 1, ..., end - 1
//
//  - - - - - - -
//  s             e
int max0(int * start, int * end)
{
    if (start >= end - 1)
    {
        return *start;
    }
    else // recursive
    {
        int maximum  = max0(start, end - 1);
        int lastval = *(end - 1);
        return (maximum >= lastval ? maximum : lastval);
    }
}


int max1(int * start, int * end)
{
    if (start >= end - 1)
    {
        return *start;
    }
    else // recursive
    {
        int maximum  = max1(start + 1, end);
        int firstval = *start;
        return (maximum >= firstval ? maximum : firstval);
    }
}

int max2(int * start, int * end)
{
    if (start >= end - 1)
    {
        return *start;
    }
    else // recursive
    {
        int step = (end - start) / 2;
        int * mid = start + step;
        int leftmax = max2(start, mid);
        int rightmax = max2(mid, end);
        return (leftmax >= rightmax ? leftmax : rightmax);
    }
}


int main()
{
    int x[] = {5, 3, 1, 2, 4, 6};

    std::cout << max0(&x[0], &x[6]) << '\n';;
    std::cout << max1(&x[0], &x[6]) << '\n';
    std::cout << max2(&x[0], &x[6]) << '\n';
    return 0;
}
