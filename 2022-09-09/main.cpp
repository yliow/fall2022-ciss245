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

void bubblesort(int x[], int n)
{
    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (x[j] > x[j + 1])
            {
                int t = x[j];
                x[j] = x[j + 1];
                x[j + 1] = t;
            }
            println(x, n);
        }
        std::cout << '\n';
    }
}

int binarysearch(int x[], int n, int target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        std::cout << left << ' ' << mid << ' ' << right << '\n';
        if (x[mid] == target)
        {
            return mid;
        }
        else if (x[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1; 
        }
        std::cout << left << ' ' << mid << ' ' << right << '\n';
        std::cout << '\n';
    }
    return -1;
}

int main()
{
    const int N = 1024;
    int x[N];
    int n = 10;
    randarray(x, n);
    println(x, n);

    std::cout << '\n';
    bubblesort(x, n);

    int target;
    std::cin >> target;
    int i = binarysearch(x, n, target);
    std::cout << i << '\n';
    return 0;
}
