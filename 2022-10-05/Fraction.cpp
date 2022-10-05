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

void Fraction_println(const Fraction & f)
{
    Fraction_print(f);
    std::cout << '\n';
}

//      f0.n               f1.n
// f0 = ---- increment by  ----
//      f0.d               f1.d
//
// i.e., f0 becomes
//
//  f0.n   f1.n   f0.n * f1.d + f0.d * f1.n 
//  ---- + ---- = -------------------------
//  f0.d   f1.d           f0.d * f1.d
Fraction Fraction_addeq(Fraction & f0, const Fraction & f1)
{
    f0.n = f0.n * f1.d + f0.d * f1.n;
    f0.d = f0.d * f1.d;
    return f0;
}

Fraction operator+=(Fraction & f0, const Fraction & f1)
{
    f0.n = f0.n * f1.d + f0.d * f1.n;
    f0.d = f0.d * f1.d;
    return f0;
}

Fraction operator+(const Fraction & f0, const Fraction & f1)
{
    Fraction ret = {f0.n * f1.d + f0.d * f1.n, f0.d * f1.d};
    return ret;
}