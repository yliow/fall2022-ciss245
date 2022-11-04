#include <iostream>
#include <string>
#include "IntDynArray.h"

IntDynArray::IntDynArray(int capacity)
    : p_(new int[capacity]), size_(0), capacity_(capacity)
{}

IntDynArray::IntDynArray(const IntDynArray & a)
    : p_(new int[a.capacity_]), size_(a.size_),
      capacity_(a.capacity_)
{
    for (int i = 0; i < a.size_; ++i)
    {
        p_[i] = a.p_[i];
    }
}

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

int IntDynArray::operator[](int i) const
{
    return p_[i];
}

int & IntDynArray::operator[](int i)
{
    return p_[i];
}

std::ostream & operator<<(std::ostream & cout,
                          const IntDynArray & a)
{
    cout << '{';
    std::string delim = "";
    for (int i = 0; i < a.size(); ++i)
    {
        cout << delim << a[i]; delim = ", ";
    }
    cout << '}';
    return cout;
}


void IntDynArray::operator=(const IntDynArray & a)
{
    if (this != &a)
    {
        if (a.size_ > capacity_)
        {
            // if not enough, need to reallocate ...
            delete [] p_;
            p_ = new int[a.size_];
            capacity_ = a.size_;
        }
        size_ = a.size_;
        for (int i = 0; i < a.size_; ++i)
        {
            p_[i] = a.p_[i];
        }
    }
}
