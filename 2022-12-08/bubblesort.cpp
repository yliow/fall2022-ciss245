#include <iostream>

void swap(int * p, int * q)
{
    int t = *p; *p = *q; *q = t;
}

void bubblesort_pass(int * start, int * end)
{
    if (start >= end - 1)
    {
    }
    else
    {
        if (*start > *(start + 1))
        {
            swap(start, start + 1);
        }
        bubblesort_pass(start + 1, end);
    }
}

void bubblesort(int * start, int * end)
{
    if (start >= end - 1)
    {
    }
    else
    {
        bubblesort_pass(start, end);
        bubblesort(start, end - 1);
    }
}

void println(int * start, int * end)
{
    if (start >= end)
    {
        std::cout << '\n';
    }
    else
    {
        std::cout << *start << ' ';
        println(start + 1, end);
    }
}

int main()
{
    int x[] = {8, 6, 4, 2, 0, 1, 3, 5, 7, 9};
    bubblesort(&x[0], &x[10]);
    println(&x[0], &x[10]);
    return 0;
}
