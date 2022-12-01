#include <iostream>

class GameObject // any visible eneity of the game
{
public:
    //  GameObject(int x, int y, int r, int g, int b,
    //             int dx, int dy)
    //      : x_(x), y_(y), 
    //        r_(r), g_(g), b_(b),
    //        dx_(dx), dy_(dy)
    // {}
    GameObject(int x)
        : x_(x)
    {
        std::cout << "GameObject::GameObject() ... x:" << x << "\n";
    }
    int get_x() const
    {
        return x_;
    }
private:
    int x_, y_;
    int r_, g_, b_;
    int dx_, dy_;    
};

class Star: public GameObject
{
public:
    Star(int x, int y, int radius, int r, int g, int b,
         int dx, int dy)
        : GameObject(x),
          y_(y), radius_(radius),
          r_(r), g_(g), b_(b),
          dx_(dx), dy_(dy)
    {}
    int get_x() const
    {
        return 999999999;
    }
    void print() const
    {
        std::cout << "star at " << get_x() << '\n';
    }
private:
    int y_, radius_;
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
    Star star(42, 0, 5, 255, 255, 255, 0, 1);
    Laser laser(100, 200, 5, 8, 255, 255, 255, 0, 1);
    
    star.print();
    laser.print();

    return 0;
}
