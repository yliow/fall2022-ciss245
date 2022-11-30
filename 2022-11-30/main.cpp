#include <iostream>

// int max(int x, int y)
// {
//     return (x >= y ? x : y);
// }

// double max(double x, double y)
// {
//     return (x >= y ? x : y);
// }

template < typename T >
T max(T x, T y)
{
    return (x >= y ? x : y);
}

int main()
{
    std::cout << max(2, 5) << '\n';
    std::cout << max(5, 2) << '\n';

    std::cout << max(2.2, 5.2) << '\n';
    std::cout << max(5.2, 2.2) << '\n';

    std::cout << max('a', 'b') << '\n';
    std::cout << max('b', 'a') << '\n';

    return 0;
}
    
