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

    //std::cout << today.yyyy_ << '\n';
    std::cout << today.get_year() << '\n';
    std::cout << today.get_month() << '\n';
    std::cout << today.get_day() << '\n';
    today.set_year(3000);
    today.print();

    std::cout << today.equals(yesterday) << '\n';
    std::cout << (today == yesterday) << '\n';
    // today.operator==(yesterday)
    std::cout << (today != yesterday) << '\n';
    // today.operator!=(yesterday)

    std::cout << today << '\n';;
    // operator<<(std::cout, today);
    Date dummy = (today += 1);
    std::cout << today << '\n';;
    std::cout << dummy << '\n';;

    //Date tmp = dummy + 1; // same as dummy.operator+(1)
    //std::cout << tmp << '\n';

    std::cout << (1 + dummy) << '\n';

    Date d(2022, 10, 24);
    std::cout << "d: " << d << '\n'; 
    return 0;
}







