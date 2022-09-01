#include <iostream>


void draw_line(int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << '*';
    }
    std::cout << '\n';
}


void draw_line_2(int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << (i % 2 == 0 ? '*' : '@');
    }
    std::cout << '\n';
}


void triangle(int n)
{
    for (int i = n; i >= 1; --i)
    {
        draw_line(i);
    }
}


int main()
{
    int n;
    std::cin >> n;
    draw_line(n);
    draw_line_2(n);
    triangle(n);
    
    return 0;
}
