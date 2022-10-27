#include <iostream>

// file: IntPointer.h
class IntPointer
{
public:
    //IntPointer(){} // g++ gives u if you do not have any default constructor
    IntPointer(int);
    IntPointer(const IntPointer & q); // g++ gives u for free if u dont have 1
    ~IntPointer();
    int operator*() const;
    int & operator*();
    const IntPointer & operator=(const IntPointer & q);
private:
    int * p_;
};

// file: IntPointer.cpp
IntPointer::IntPointer(int val)
    : p_(new int)
{
    *p_ = val;
}

IntPointer::IntPointer(const IntPointer & q)
    : p_(new int)
{
    *p_ = *(q.p_);
}

IntPointer::~IntPointer()
{
    std::cout << "IntPointer::~IntPointer() ...\n";
    delete p_;
}

int IntPointer::operator*() const
{
    return *p_;
}

int & IntPointer::operator*()
{
    return *p_;
}

const IntPointer & IntPointer::operator=(const IntPointer & q)
{
    *p_ = *(q.p_);
    return (*this);
}

void f()
{
   IntPointer p(42);    
   IntPointer q(-1);
   p = q;
   std::cout << *p << ' ' << *q << '\n';
}

int main()
{
    // int * p = new int;
    // *p = 42;
    // std::cout << (*p) << '\n';
    // delete p;

    IntPointer p(0); // object p contains a pointer, constructor auto allocate
                     // an integer value for object p point to.
                     // The pointer inside p is called p_.
    std::cout << *p << '\n'; // *p is p.operator*()
    *p = 42;
    std::cout << *p << '\n';
    // no need to deallocate p.p_ ... do that in the destructor

    f();
    
    return 0;
} // p calls destructor .... p memleak
