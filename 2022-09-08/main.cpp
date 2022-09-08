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

int sum(int x[], int n)
{
    int s = 0;
    for (int i = 0; i < n; ++i)
    {
        s += x[i];
    }
    return s;
}

//double avg(int x[], int n);

int max(int x[], int n)
{
    int m = x[0];
    for (int i = 1; i < n; ++i)
    {
        if (x[i] > m)
        {
            m = x[i];
        }
    }
    return m;
}

int linearsearch(int x[], int n, int target)
{
    for (int i = 0; i < n; ++i)
    {
        if (x[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    srand((unsigned int) time(NULL));
    
    const int N = 1024;
    int x[N];
    randarray(x, 5);
    println(x, 5);
    int s = sum(x, 5);
    std::cout << s << '\n';
    std::cout << max(x, 5) << '\n';
    return 0;
}
