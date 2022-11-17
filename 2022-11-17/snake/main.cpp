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
        case 'w':
            return N;
        case 's':
            return S;
        case 'a':
            return W;
        case 'd':
            return E;
        case 'n':
            return NO_OPTION;
    }
    return -1;
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
    char & operator()(int x, int y)
    {
        return surface_[y][x];
    }
    void clear()
    {
        for (int r = 0; r < 5; ++r)
        {
            for (int c = 0; c < 10; ++c)
                surface_[r][c] = ' ';
        }
    }
    void draw() const
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
    Apple(Surface * psurface,
          int x=0, int y=0)
        : psurface_(psurface), x_(rand() % 10), y_(rand() % 5), is_alive_(true)
    {}
    void set(int x, int y)
    {
        x_ = x; y_ = y;
    }
    void reset()
    {
        x_ = rand() % 10;
        y_ = rand() % 5;
        is_alive_ = true;
    }
    void draw() const
    {
        if (is_alive_)
        {
            (*psurface_)(x_, y_) = 'A';
        }
    }
    int x() const { return x_; }
    int y() const { return y_; }
    bool & is_alive()
    {
        return is_alive_;
    }
private:
    Surface * psurface_;
    int x_, y_;
    bool is_alive_;
};

class Head
{
public:
    Head(Surface * psurface,
         int x, int y, int direction)
        : psurface_(psurface), x_(x), y_(y), direction_(direction)
    {}
    int x() const
    {
        return x_;
    }
    int y() const
    {
        return y_;
    }
    void draw() const
    {
        char headchar[4] = {'^', 'V', '>', '<'};
        (*psurface_)(x_, y_) = headchar[direction_];
    }
    bool move(int direction)
    {
        if (direction != NO_OPTION)
        {
            direction_ = direction;
        }
        switch (direction_)
        {
            case N:
            {
                --y_;
                if (y_ < 0)
                {
                    y_ = 0;
                    return false;
                }
                break;
            }
            case S:
            {
                ++y_;
                if (y_ > 4)
                {
                    y_ = 4;
                    return false;
                }
                break;
            }
            case W:
            {
                --x_;
                if (x_ < 0)
                {
                    x_ = 0;
                    return false;
                }
                break;
            }
            case E:
            {
                ++x_;
                if (x_ > 9)
                {
                    x_ = 9;
                    return false;
                }
                break;
            }
        }
        return true;
    }
    int direction() const
    {
        return direction_;
    }
private:
    Surface * psurface_;
    int x_, y_;
    int direction_;
};

class Body
{
public:
    Body(Surface * psurface, int x, int y, int direction, int length)
        : psurface_(psurface), x_(length - 1), y_(length - 1)
    {
        switch (direction)
        {
            case N:
            {
                ++y;
                for (int i = 0; i < length - 1; ++i)
                {
                    x_[i] = x; y_[i] = y; ++y;
                }
                break;
            }
            case S:
            {
                --y;
                for (int i = 0; i < length - 1; ++i)
                {
                    x_[i] = x; y_[i] = y; --y;
                }
                break;
            }
            case E:
            {
                --x;
                for (int i = 0; i < length - 1; ++i)
                {
                    x_[i] = x; y_[i] = y; --x;
                }
                break;
            }
            case W:
            {
                ++x;
                for (int i = 0; i < length - 1; ++i)
                {
                    x_[i] = x; y_[i] = y; ++x;
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
    void shift_head_to_tail(int x, int y)
    {
        for (int i = x_.size() - 1; i > 0; --i)
        {
            x_[i] = x_[i - 1];
            y_[i] = y_[i - 1];
        }
        x_[0] = x;
        y_[0] = y;
    }
    void insert_head(int x, int y)
    {
        x_.resize(x_.size() + 1);
        y_.resize(y_.size() + 1);
        for (int i = x_.size() - 1; i > 0; --i)
        {
            x_[i] = x_[i - 1];
            y_[i] = y_[i - 1];
        }
        x_[0] = x;
        y_[0] = y;
    }
private:
    Surface * psurface_;
    std::vector< int > x_; // x_[0], y_[0] is next to head
    std::vector< int > y_;
};

class Snake
{
public:
    Snake(Surface * psurface,
          int x, int y, // head position
          int direction,
          int length)   // total length
        : head_(psurface, x, y, direction),
          body_(psurface, x, y, direction, length)
    {}
    const Head & head() const
    {
        return head_;
    }
    void draw() const
    {
        head_.draw();
        body_.draw();
    }
    void move(int option, Apple & a)
    {
        int x = head_.x();
        int y = head_.y();
        bool moved = head_.move(option);
        if (moved)
        {
            // if ate apple
            if (head_.x() == a.x() && head_.y() == a.y())
            {
                a.is_alive() = false;
                body_.insert_head(x, y);
            }
            else
            {
                body_.shift_head_to_tail(x, y);
            }
        }
    }
    int x() // head's x
    {
        return head_.x();
    }
    int y() // head's y
    {
        return head_.y();
    }
private:
    Head head_;
    Body body_;
};



int main()
{
    srand((unsigned int) time(NULL));
    Surface surface;
    Apple a(&surface);
    Snake snake(&surface, 4, 2, N, 3);

    bool game_ended = false;
    int steps = 0;
    while (not game_ended)
    {
        surface.clear();
        a.draw();
        snake.draw();
        surface.draw();
        
        std::cout << "w-north s-south d-east a-west n-no input: ";
        char option;
        std::cin >> option;
        if (option == '!')
        {
                std::cout << "number of auto steps: ";
                std::cin >> steps;
        }
        int direction = to_direction(option);
        snake.move(direction, a);
        if (!a.is_alive())
        {
            a.reset();
        }
    }
    
    return 0;
}
