// Date.cpp
#include <iostream>
#include "Date.h"

void Date::init(int yyyy, int mm, int dd)
{
    yyyy_ = yyyy;
    mm_ = mm;
    dd_ = dd;
}

void Date::print()
{
    std::cout << yyyy_ << '/'
              << mm_ << '/'
              << dd_<< '\n';
}

void Date::add_y(int inc)
{
    yyyy_ += inc;
}

void Date::add_m(int inc)
{
    mm_ += inc;
}

void Date::add_d(int inc)
{
    dd_ += inc;
}

void Date::add_m_d(int inc_mm,
                   int inc_dd)
{
    add_m(inc_mm);
    add_d(inc_dd);
}

void Date::add_date(const Date & date)
{
    add_y(date.yyyy_);
    add_m(date.mm_);
    add_d(date.dd_);
}
