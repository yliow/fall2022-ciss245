// Date.h
#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
public:
    void init(int, int, int);
    void print();
    void add_y(int);
    void add_m(int);
    void add_d(int);
    void add_m_d(int, int);
    void add_date(const Date &);
    int get_year();
    void set_year(int);
    int get_month();
    void set_month(int);
    int get_day();
    void set_day(int);
    bool equals(const Date &);
    bool operator==(const Date &);
    bool operator!=(const Date &);
private:
    int yyyy_, mm_, dd_;
};

void init(int, int, int);
std::ostream & operator<<(std::ostream &, Date &);

#endif
