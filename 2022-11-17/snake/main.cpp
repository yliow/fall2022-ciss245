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


class Head
{
public:
    Head(Surface * psurface, int x, int y, int dir)
        : psurface_(psurface), x_(x), y_(y), dir_(dir)
    {}
    int x() const { return x_; }
    int y() const { return y_; }
    void draw() const
    {
        char h[4] = {'^', 'V', '>', '<'};
        (*psurface_)(x_, y_) = h[dir_];
    }
    void move(int direction)
    {
        if (direction == NO_OPTION)
        {
            direction = dir_;
        }
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

class Body
{
public:
    Body(Surface * psurface, int x, int y, int direction)
        : psurface_(psurface), x_(2), y_(2)
    {
        switch (direction)
        {
            case N:
            {
                ++y;
                for (int i = 0; i < 2; ++i)
                {
                    x_[i] = x;
                    y_[i] = y; ++y;
                }
                break;
            }
            case S:
            {
                --y;
                for (int i = 0; i < 2; ++i)
                {
                    x_[i] = x;
                    y_[i] = y; --y;
                }
                break;
            }
            case E:
            {
                --x;
                for (int i = 0; i < 2; ++i)
                {
                    x_[i] = x; --x;
                    y_[i] = y;
                }
                break;
            }
            case W:
            {
                ++x;
                for (int i = 0; i < 2; ++i)
                {
                    x_[i] = x; ++x;
                    y_[i] = y;
                }
                break;
            }

        }
    }
    void draw() const
    {
        for (unsigned int i = 0; i < x_.size(); ++i)
        {
            (*psurface_)(x_[i], y_[i]) = '@';
        }
    }
    void move(int x, int y)
    {
        for (unsigned int i = x_.size() - 1; i >= 1; --i)
        {
            x_[i] = x_[i - 1];
            y_[i] = y_[i - 1];
        }
        x_[0] = x;
        y_[0] = y;
    }
private:
    Surface * psurface_;
    std::vector< int > x_;
    std::vector< int > y_;
};

class Snake
{
public:
    Snake(Surface * psurface, int x, int y, int direction)
        : head_(psurface, x, y, direction), body_(psurface, x, y, direction)
    {}
    void draw() const
    {
        head_.draw();
        body_.draw();
    }
    void move(int direction)
    {
        int x = head_.x();
        int y = head_.y();
        head_.move(direction);
        body_.move(x, y);
    }
private:
    Head head_;
    Body body_;
};


int main()
{
    srand((unsigned int) time(NULL));
    Surface surface;
    Apple a(&surface, 0, 0);
    Snake snake(&surface, 3, 3, W);

    bool game_ended = false;
    while (not game_ended)
    {
        surface.clear();
        a.draw();
        snake.draw();
        surface.draw();
        std::cout << "w-north s-south d-east a-west n-no input: ";
        char option;
        std::cin >> option;
        int direction = to_direction(option);
        snake.move(direction);
    }
    
    return 0;
}
