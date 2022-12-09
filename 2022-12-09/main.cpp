#include <iostream>
#include <cstdlib>
#include <ctime>

class Dog
{
public:
    Dog()
        : num_legs_(4)
    {}
    void talk()
    {
        std::cout << "bowwow\n";
    }
    int num_legs_;
};

class Cat
{
public:
    Cat()
        : num_legs_(4)
    {}
    void talk()
    {
        if (rand() % 2 == 0)
        {
            std::cout << "meow\n";
        }
    }
    int num_legs_;
};

int main()
{
    srand((unsigned int) time(NULL));
    Dog dog;
    Cat cat;
    dog.talk();
    cat.talk();
    return 0;
}
