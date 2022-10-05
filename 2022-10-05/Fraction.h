#ifndef FRACTION_H
#define FRACITON_H

struct Fraction
{
    int n;
    int d;
};

void Fraction_set(Fraction &, int, int);
void Fraction_set(Fraction *, int, int);
void Fraction_print(const Fraction &);
void Fraction_println(const Fraction &);
Fraction Fraction_addeq(Fraction & f0, const Fraction & f1);
Fraction operator+=(Fraction & f0, const Fraction & f1);
Fraction operator+(const Fraction & f0, const Fraction & f1);
#endif
