#include <iostream>

// file: IntPointer.h
class IntPointer
{
public:
    //IntPointer(){} // g++ gives u if you do not have any default constructor
    IntPointer(int);
    //IntPointer(const IntPointer & x){} // g++ gives u for free if u dont have 1
    ~IntPointer();
    int operator*() const;
    int & operator*();
private:
    int * p_;
};

// file: IntPointer.cpp
IntPointer::IntPointer(int val)
    : p_(new int)
{ *p_ = val; }
IntPointer::~IntPointer()
{
    std::cout << "IntPointer::~IntPointer() ...\n";
    delete p_;
}
int IntPointer::operator*() const { return *p_; }
int & IntPointer::operator*() { return *p_; }

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

    return 0;
} // p calls destructor
