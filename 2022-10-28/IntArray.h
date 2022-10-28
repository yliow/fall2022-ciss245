#ifndef INTARRAY_H
#define INTARRAY_H

class IntArray
{
public:
    IntArray()
        : size_(0), capacity_(10)
    {}
//private:
    int x_[10];
    int size_;
    int capacity_;
};

std::ostream & operator<<(std::ostream &, const IntArray &);

#endif
