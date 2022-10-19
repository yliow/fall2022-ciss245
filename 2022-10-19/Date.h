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
    int get_year() const;
    void set_year(int);
    int get_month() const;
    void set_month(int);
    int get_day() const;
    void set_day(int);
    bool equals(const Date &);
    bool operator==(const Date &);
    bool operator!=(const Date &);
    Date operator+=(int);
    Date operator+(int);
private:
    int yyyy_, mm_, dd_;
};

void init(int, int, int);
std::ostream & operator<<(std::ostream &, const Date &);
Date operator+(int, const Date &);

#endif
