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

template < typename S, typename T >
T f(T x, S y)
{
    return x + 2 / y;
}

int main()
{
    std::cout << max< int >(2, 5) << '\n';
    std::cout << max< int >(5, 2) << '\n';

    std::cout << max< double >(2.2, 5.2) << '\n';
    std::cout << max< double >(5.2, 2.2) << '\n';

    std::cout << max< char >('a', 'b') << '\n';
    std::cout << max< char >('b', 'a') << '\n';

    std::cout << f< int, double >(2, 3.14) << '\n';
    return 0;
}
    
