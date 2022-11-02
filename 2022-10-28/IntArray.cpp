#include <iostream>
#include <string>
#include "IntArray.h"


int IntArray::size() const
{
    return size_;
}


int IntArray::capacity() const
{
    return capacity_;
}


std::ostream & operator<<(std::ostream & cout, const IntArray & a)
{
    cout << '{';
    std::string delim = "";
    for (int i = 0; i < a.size(); ++i)
    {
        cout << delim << a.x_[i]; delim = ", ";
    }
    cout << '}';
    return cout;
}


void IntArray::push_back(int v)
{
    if (size_ < capacity_)
    {
        x_[size_] = v;
        ++size_;
    }
}


void IntArray::push_front(int v)
{
    if (size_ < capacity_)
    {
        for (int i = size_; i > 0; --i)
        {
            x_[i] = x_[i - 1];
        }
        x_[0] = v;
        ++size_;
    }
}

