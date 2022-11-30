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

template < typename T >
void swap(T & x, T & y)
{
    T t = x;
    x = y;
    y = t;
}

template < typename T >
class vec2
{
public:
    vec2(T x, T y)
        : x_(x), y_(y)
    {}
    T operator[](int i) const
    {
        return (i == 0 ? x_ : y_);
    }
private:
    T x_, y_;
};

template < typename T >
std::ostream & operator<<(std::ostream & cout, const vec2< T > & v)
{
    cout << '<' << v[0] << ", " << v[1] << '>';
    return cout;
}

int main()
{
    // std::cout << max< int >(2, 5) << '\n';
    // std::cout << max< int >(5, 2) << '\n';
    // std::cout << max< double >(2.2, 5.2) << '\n';
    // std::cout << max< double >(5.2, 2.2) << '\n';
    // std::cout << max< char >('a', 'b') << '\n';
    // std::cout << max< char >('b', 'a') << '\n';
    // std::cout << f< int, double >(2, 3.14) << '\n';

    // int i = 2, j = 5;
    // swap< int >(i, j);
    // std::cout << i << ' ' << j << '\n';

    // char c = 'a', d = '$';
    // swap< char >(c, d);
    // std::cout << c << ' ' << d << '\n';

    vec2< int > v(1, 2);
    vec2< double > u(1.1, 2.2);
    std::cout << v << '\n';
    std::cout << u << '\n';
    
    return 0;
}
    
