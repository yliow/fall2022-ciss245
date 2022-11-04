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
    if (size_ < capacity_)
    {
        size_ = size;
    }
    else
    {
        delete [] p_;
        p_ = new int[size];
        capacity_ = size;
        size_ = size;
        for (int i = 0; i < a.size_; ++i)
        {
            p_[i] = a.p_[i];
        }
    }
}

int IntDynArray::operator[](int i) const
{
    return p_[i];
}

// int IntDynArray::at(int i) const
// {
//     if (0 < i && i < size_)
//     {
//         return p_[i];
//     }
//     else
//     {
//         throw std::exception
//     }
// }

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
            int * q = new int[a.size_];
            for (int i = 0; i < a.size_; ++i)
            {
                q[i] = p_[i];
            }
            delete [] p_;
            p_ = q;
            size_ = a.size_;
            capacity_ = a.size_;
        }
        else // ?
        {
            size_ = a.size_;
            for (int i = 0; i < a.size_; ++i)
            {
                p_[i] = a.p_[i];
            }
        }
    }
}
