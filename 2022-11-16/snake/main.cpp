#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

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
    char & operator()(int x, int y)
    {
        return surface_[y][x];
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

class Apple
{
public:
    Apple(Surface * psurface, int x=0, int y=0)
        : psurface_(psurface), x_(rand() % 10), y_(rand() % 5)
    {}
    void set(int x, int y)
    {
        x_ = x; y_ = y;
    }
    int x() const { return x_; }
    int y() const { return y_; }
    void draw()
    {
        (*psurface_)(x_, y_) = 'A';
    }
private:
    Surface * psurface_;
    int x_, y_;
};

class Snake
{
    
};

class Head
{
public:
    Head(Surface * psurface, int x, int y, int dir)
        : psurface_(psurface), x_(x), y_(y), dir_(dir)
    {}
    int x() const { return x_; }
    int y() const { return y_; }
    void draw()
    {
        (*psurface_)(x_, y_) = 'H';
    }
private:
    Surface * psurface_;
    int x_, y_;
    int dir_;
};



int main()
{
    srand((unsigned int) time(NULL));
    Surface surface;
    Apple a(&surface);
    //Snake snake;
    Head head(&surface, 4, 3, 1);

    bool game_ended = false;
    while (not game_ended)
    {
        surface.clear();
        a.draw();
        //surface.put(head);
        surface.draw();
        std::cout << "w-north s-south d-east a-west n-no input: ";
        char option;
        std::cin >> option;
    }
    
    return 0;
}
