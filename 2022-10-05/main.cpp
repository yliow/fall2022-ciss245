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
    // Time t0;
    // t0.hour = 2;
    // t0.min = 51;
    // t0.sec = 15;
    // Time_println(t0);
    
    Fraction f0;
    Fraction_set(f0, 1, 2);
    std::cout << "f0 = ";
    Fraction_println(f0);
    
    Fraction f1;
    Fraction_set(f1, 1, 3);

    //f0 += f1
    // Fraction_addeq(f0, f1);
    f0 += f1; // ----> operator+=(f0, f1)
    std::cout << "f0 = ";
    Fraction_println(f0);

    f0 = f0 + f1; // f0 + f1 ----> opeartor+(f0, f1)
    Fraction_println(f0);

    return 0;
}

