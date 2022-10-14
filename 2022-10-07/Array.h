#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

struct Array
{
    int x[5];
    int size;
    int capacity;
};

void Array_init(Array & a);
void Array_pushback(Array & a, int v);
void Array_popback(Array & a);
std::ostream & operator<<(std::ostream &, const Array &);

#endif
