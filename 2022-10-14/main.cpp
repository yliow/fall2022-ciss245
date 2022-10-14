// main.cpp
#include <iostream>
#include "Date.h"

int main()
{
    Date today, yesterday;
    today.init(2022, 10, 14);
    today.print();
    
    yesterday.init(2022, 10, 13);
    yesterday.print();

    today.add_m_d(1, 2);
    today.print();

    Date one_day;
    one_day.init(0, 0, 1);
    today.add_date(one_day);
    today.print();

    return 0;
}
