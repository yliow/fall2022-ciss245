#include <iostream>
#include <string>
#include "IntArray.h"

std::ostream & operator<<(std::ostream & cout, const IntArray & a)
{
    cout << '{';
    std::string delim = "";
    for (int i = 0; i < a.size_; ++i)
    {
        cout << delim << a.x_[i]; delim = ", ";
    }
    cout << '}';
    return cout;
}
