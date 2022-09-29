#include <iostream>
void swap3(int * p, int * q)
{
    int t = *p;
    *p = *q;
    *q = t;
}
void swap2(int & x, int & y) { int t = x; x = y; y = t; }
void swap1(int x, int y) { int t = x; x = y; y = t; }

int main()
{
    int i = 42, j = 0;
    swap1(i, j);
    swap2(i, j);
    swap2(&i, &j);
    return 0;
}
