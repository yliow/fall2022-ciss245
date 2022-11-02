#ifndef INTARRAY_H
#define INTARRAY_H

class IntArray
{
public:
    IntArray()
        : size_(0), capacity_(10)
    {}
    int size() const;
    int capacity() const;

    int operator[](int) const; // if a is an IntArray object, a[i] is a.operator[](i)
    int & operator[](int);
    
    void push_back(int);
    void push_front(int);
    
//private:
    int x_[10];
    int size_;
    int capacity_;
};

std::ostream & operator<<(std::ostream &, const IntArray &);

#endif
