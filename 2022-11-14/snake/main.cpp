#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

class Apple
{
public:
    Apple(int x=0, int y=0)
        : x_(rand() % 10), y_(rand() % 5)
    {}
    void set(int x, int y)
    {
        x_ = x; y_ = y;
    }
    int x() const { return x_; }
    int y() const { return y_; }
private:
    int x_, y_;
};

class Snake
{
    
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
    void put(const Apple & a)
    {
        surface_[a.y()][a.x()] = 'A';
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
    srand((unsigned int) time(NULL));
    Surface surface;
    Apple a;
    Snake snake;

    bool game_ended = false;
    while (not game_ended)
    {
        surface.clear();
        surface.put(a);
        surface.draw();
        std::cout << "w-north s-south d-east a-west n-no input: ";
        char option;
        std::cin >> option;
    }
    
    return 0;
}
