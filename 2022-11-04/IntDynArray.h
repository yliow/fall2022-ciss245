//=========================================================
//
// File: IntDynArray.h
// Author: John Doe
//
// Description
// This library models a dynamic array objects. A dynamic
// array is one that "expand" and "contracts" auto-magically
// by itself, i.e., the object has a pointer to an array
// in the heap.
//
// METHODS:
// f(int)        f(i) will ....
//
// USAGE:
// IntDynArray a(5); // a models an array of capacity 5
// a.push_front(42); // a = {42}
// a.push_back(-1);  // a = {42, -1}
//=========================================================

#ifndef INTDYNARRAY_H
#define INTDYNARRAY_H
#include <iostream>

class IntDynArray
{
public:
    IntDynArray(int);
    ~IntDynArray();
    IntDynArray(const IntDynArray &);
    int size() const;
    void resize(int);
    int operator[](int) const;
    int & operator[](int);
    void operator=(const IntDynArray &);
//private:
    int capacity_;
  private:
    int size_;
    int * p_;
};

std::ostream & operator<<(std::ostream &,
                          const IntDynArray &);

#endif

