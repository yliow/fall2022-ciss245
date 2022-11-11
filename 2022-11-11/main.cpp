#include <iostream>

class Apple
{
public:
    Apple(int x=0, int y=0)
        : x_(x), y_(y)
    {}
private:
    int x_, y_;
};

class Surface
{
public:
    Surface()
    {
        for (int r = 0; r < 5; ++r)
        {
            for (int c = 0; c < 10; ++c)
                surface_[r][c] = ' ';
        }
    }
    void clear()
    {
        for (int r = 0; r < 5; ++r)
        {
            for (int c = 0; c < 10; ++c)
                surface_[r][c] = ' ';
        }
    }
    void draw()
    {
        std::cout << '+';
        for (int c = 0; c < 10; ++c) std::cout << '-';
        std::cout << "+\n";
        for (int r = 0; r < 5; ++r)
        {
            std::cout << '|';
            for (int c = 0; c < 10; ++c)
                std::cout << surface_[r][c];
            std::cout << "|\n";
        }
        std::cout << '+';
        for (int c = 0; c < 10; ++c) std::cout << '-';
        std::cout << "+\n";
    }
private:
    // 10x10
    char surface_[5][10];
};

int main()
{
    Surface surface;
    Apple a;
    surface.draw();
    return 0;
}
