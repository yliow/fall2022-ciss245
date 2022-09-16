#include <iostream>

void Array_print(int x[], int size=10);

void Array_print(int x[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << x[i] << ' ';
    }
}


void Array_println(int x[], int size=10)
{
    Array_print(x, size);
    std::cout << '\n';
}

// sum_int_int
int sum(int i, int j)
{
    return i + j;
}

// sum_double_double
double sum(double i, double j)
{
    return i + j;
}
// sum_double_double
int sum(double i, double j)
{
    return i + j;
}

int main()
{
    // int x[1024];
    // std::cout << "x: ";
    // Array_println(x); // <-- warning
    // Array_println(x, 15);
    // Array_println(x, 3);

    int i = 0, j = 1;
    int z = sum(i, j);
    std::cout << z << '\n';

    double x = 0.1, y = 0.2;
    std::cout << sum(x, y) << '\n';

    return 0;
}
