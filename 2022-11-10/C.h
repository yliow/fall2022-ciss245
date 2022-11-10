#ifndef C_H
#define C_H

class C
{
public:
    C(int x): i(x) {}
    int i;
    static void increment_j();
    static int get_j();
  private:
    static int j;
};

#endif
