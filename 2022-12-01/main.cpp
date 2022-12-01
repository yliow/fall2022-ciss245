#include <iostream>

class Star
{
public:
    Star(int x, int y, int radius, int r, int g, int b,
         int dx, int dy)
        : x_(x), y_(y), radius_(radius),
          r_(r), g_(g), b_(b),
          dx_(dx), dy_(dy)
    {}
    int get_x() const
    {
        return x_;
    }
    void print() const
    {
        std::cout << "star at " << x_ << '\n';
    }
private:
    int x_, y_, radius_;
    int r_, g_, b_;
    int dx_, dy_;
};

class Laser
{
public:
    Laser(int x, int y, int w, int h,
          int r, int g, int b,
          int dx, int dy)
        : x_(x), y_(y), w_(w), h_(h),
          r_(r), g_(g), b_(b),
          dx_(dx), dy_(dy)
    {}
    int get_x() const
    {
        return x_;
    }
    void print() const
    {
        std::cout << "laser at " << x_ << '\n';
    }
private:
    int x_, y_, w_, h_;
    int r_, g_, b_;
    int dx_, dy_;
};

int main()
{
    Star star(0, 0, 5, 255, 255, 255, 0, 1);
    Laser laser(100, 200, 5, 8, 255, 255, 255, 0, 1);
    
    star.print();
    laser.print();

    return 0;
}
