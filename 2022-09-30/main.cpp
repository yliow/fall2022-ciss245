#include <iostream>
#include <cstddef>

void f()
{
    int * p = new int;
    // mem leak
    // must do delete p;
    return;
}

int main()
{
    //f();
    while (1)
    {
        double * q = new double[1000000];
    }
    return 0;
}
