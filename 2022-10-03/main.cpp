#include <iostream>
#include <iomanip>
#include "Fraction.h"

struct Time
{
    int hour;
    int min;
    int sec;
};

void Time_print(const Time & t)
{
    std::cout << std::setw(2) << std::setfill('0')
              << t.hour
              << ':'
              << std::setw(2) << std::setfill('0')
              << t.min
              << ':'<< std::setw(2) << std::setfill('0')
              << t.sec;
}

void Time_println(const Time & t)
{
    Time_print(t);
    std::cout << '\n';
}

int main()
{

    Time t0;
    t0.hour = 2;
    t0.min = 51;
    t0.sec = 15;
    Time_println(t0);
    
    Fraction f0;
    Fraction_set(f0, 1, 2);
    Fraction_print(f0);
    
    return 0;
}

