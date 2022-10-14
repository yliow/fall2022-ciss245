#include "Array.h"
void Array_init(Array & a) { a.size = 0; a.capacity = 5; }
void Array_pushback(Array & a, int v)
{
    if (a.size < a.capacity)
    {
        a.x[a.size] = v; ++a.size;
    }
    else
    {
        std::cout << "Error: capacity reached. pushback ignored.\n";
    }
}
void Array_popback(Array & a)
{
    if (a.size > 0)
    {
        --a.size;
    }
}

std::ostream & operator<<(std::ostream & cout, const Array & a)
{
    cout << '{';
    for (int i = 0; i < a.size; ++i)
    {
        cout << a.x[i];
        if (i < a.size - 1)
        {
            cout << ", ";
        }
    }
    cout << '}';
    return cout;
}
