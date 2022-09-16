#include <iostream>


void Array_print(int x[])
{
    for (int i = 0; i < 10; ++i)
    {
        std::cout << x[i] << ' ';
    }
}


void Array_println(int x[])
{
    Array_print(x);
    std::cout << '\n';
}

int main()
{
    int x[10];
    std::cout << "x: ";
    Array_println(x);
    
    return 0;
}
