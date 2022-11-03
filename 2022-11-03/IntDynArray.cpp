#include <iostream>
#include "IntDynArray.h"

IntDynArray::IntDynArray(int capacity)
    : p_(new int[capacity]), size_(0), capacity_(capacity)
{}

IntDynArray::~IntDynArray()
{
    delete [] p_;
}

int IntDynArray::size() const
{
    return size_;
}

void IntDynArray::resize(int size)
{
    size_ = size;
}

std::ostream & operator<<(std::ostream & cout,
                          const IntDynArray & a)
{
    cout << '{';
    for (int i = 0; i < a.size(); ++i)
    {
        cout << a.p_[i] << ' ';
    }
    cout << '}';
    return cout;
}
