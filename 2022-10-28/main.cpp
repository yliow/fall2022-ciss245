#include <iostream>
#include "IntArray.h"
int main()
{
    IntArray a; // a wraps a dyn array, i.e., a has x_[0..9], size_, capacity_=10;
    //a.size_ = 4;
    std::cout << a << '\n'; // {1, 3, 5, 2, 4}
    a.push_back(4);         // a <-> {4}
    std::cout << a << '\n'; // {1, 3, 5, 2, 4}
    a.push_back(6);         // a <-> {4, 6}
    std::cout << a << '\n'; // {1, 3, 5, 2, 4}
    a.push_back(3);         // a <-> {4, 6, 3}
    std::cout << a << '\n'; // {1, 3, 5, 2, 4}
    a.push_front(42);       // a <-> {42, 4, 6, 3}
    std::cout << a << '\n'; // {1, 3, 5, 2, 4}
    std::cout << a.size() << '\n';
    // a.insert(2, 99);  // a <-> {42, 4, 99, 6, 3}
    // a.pop_front();    // a <-> {4, 99, 6, 3}
    // a.pop_back();     // a <-> {4, 99, 6}
    // a.find(99);       // return index of 99 (or pointer to 99)
    // a.remove(2);      // a <-> {4, 99}
    // std::cout << a[2] << '\n'; // ???
    // a[2] = 9999999;
    // a.sort_ascending();
    // a.sort_descending();
    // a.binarysearch(v);
    // a.randomize();
    // Array b;
    // b = a;
    // a.count(4); // number of times 4 occurs in a
    // a.concat(b); //
    // a.resize(2);
    
    return 0;
}
