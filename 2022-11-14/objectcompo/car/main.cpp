#include <iostream>

class Engine
{
public:
    Engine(int id)
        : id_(id)
    {}
    void start()
    {
        std::cout << "start engine ...\n";
    }
private:
    int id_;
};

class Car
{
public:
    Car(int id)
        : id_(id), anEngine(3)
    {}
    Engine & getEngine()
    {
        return anEngine_;
    }
    void start()
    {
        anEngine_.start();
    }
private:
    int id_;
    Engine anEngine_;    
};

int main()
{
    Car aCar(42);
    aCar.start();
    
    return 0;
}
