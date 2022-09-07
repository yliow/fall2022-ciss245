#include <iostream>

/*
      zn   xn   yn   xn * yd + yn * xd
      -- = -- + -- = -----------------
      zd   xd   yd        xd * yd
       
 */
void Fraction_add(int & zn, int & zd,
                  int xn, int xd,
                  int yn, int yd);
void Fraction_print(int zn, int zd);

void Fraction_add(int & zn, int & zd,
                  int xn, int xd,
                  int yn, int yd)
{
    zn = xn * yd + yn * xd;
    zd = xd * yd;
}

void Fraction_print(int zn, int zd)
{
    std::cout << zn << '/' << zd << '\n';
}

int main()
{
    int xn, xd; // num & den of x
    int yn, yd; // num & den of y
    int zn, zd; // num & den of z

    std::cin >> xn >> xd;
    std::cin >> yn >> yd;
    Fraction_add(zn, zd, xn, xd, yn, yd);

    Fraction_print(zn, zd);
        
    return 0;
}
