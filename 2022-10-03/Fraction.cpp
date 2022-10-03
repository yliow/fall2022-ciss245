#include <iostream>
#include "Fraction.h"

void Fraction_set(Fraction & f, int n, int d)
{
    f.n = n;
    f.d = d;
}

void Fraction_print(const Fraction & f)
{
    std::cout << f.n << '/' << f.d;
}
