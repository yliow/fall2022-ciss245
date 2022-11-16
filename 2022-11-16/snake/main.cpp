#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

const int N = 0;
const int S = 1;
const int E = 2;
const int W = 3;
const int NO_OPTION = 4;

int to_direction(char option)
{
    switch (option)
    {
        case 'w': return N;
        case 's': return S;
        case 'd': return E;
        case 'a': return W;            
    }
    return NO_OPTION;
}

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
    char surface_[5][10];
};

class Apple
{
public:
    Apple(Surface * psurface, int x=0, int y=0)
        : psurface_(psurface), x_(x), y_(y)
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
        char h[4] = {'^', 'V', '>', '<'};
        (*psurface_)(x_, y_) = h[dir_];
    }
    void move(int direction)
    {
        switch (direction)
        {
            case N:
            {
                --y_;
                if (y_ < 0) y_ = 0;
                dir_ = N;
                break;
            }
            case S:
            {
                ++y_;
                if (y_ > 4) y_ = 4;
                dir_ = S;
                break;
            }
            case E:
            {
                ++x_;
                if (x_ > 9) x_ = 9;
                dir_ = E;
                break;
            }
            case W:
            {
                --x_;
                if (x_ < 0) x_ = 0;
                dir_ = W;
                break;
            }
        }
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
    Apple a(&surface, 0, 0);
    //Snake snake;
    Head head(&surface, 2, 3, 1);

    bool game_ended = false;
    while (not game_ended)
    {
        surface.clear();
        a.draw();
        head.draw();
        surface.draw();
        std::cout << "w-north s-south d-east a-west n-no input: ";
        char option;
        std::cin >> option;
        int direction = to_direction(option);
        head.move(direction);
    }
    
    return 0;
}
