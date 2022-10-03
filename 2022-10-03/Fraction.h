#ifndef FRACTION_H
#define FRACITON_H

struct Fraction
{
    int n;
    int d;
};

void Fraction_set(Fraction &, int, int);
void Fraction_print(const Fraction &);

#endif
