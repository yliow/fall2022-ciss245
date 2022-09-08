#include <iostream>
#include <ctime>
#include <cstdlib>

void randarray(int x[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        x[i] = rand() % 20;
    }
}

void print(int x[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << x[i] << ' '; 
    }
}

void println(int x[], int n)
{
    print(x, n);
    std::cout << '\n';
}

int main()
{
    srand((unsigned int) time(NULL));
    
    const int N = 1024;
    int x[N];
    randarray(x, 10);
    println(x, 10);
    return 0;
}
