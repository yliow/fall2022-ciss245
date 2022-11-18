#include <iostream>

class Int
{
public:
    explicit Int(int i)
        : i_(i)
    {}
    explicit operator int()
    {
        return i_;
    }
//private:
    int i_;
};
std::ostream & operator<<(std::ostream & cout, const Int & I)
{
    cout << "<Int " << I.i_ << '>';
    return cout;
}

void f(Int I)
{
    std::cout << "in f ... I:" << I << '\n';
}

class C
{
public:
    C(int j)
        : i(j)
    {}
    C()
        : i(42)
    {}
    int i;
};

int main()
{
    // Int I(0);
    // std::cout << I << '\n';
    // //int i = int(I);
    // int i = int(I);
    // std::cout << i << '\n';
    // f(I);
    // f(42);

    C c[100];
    std::cout << c[0].i << '\n';

    C * p[100];
    for (int i = 0; i < 100; ++i)
    {
        p[i] = new C(i);
    }

    // do useful work with p[i] ...
    
    for (int i = 0; i < 100; ++i)
    {
        delete p[i];
    }

    
    return 0;
}
