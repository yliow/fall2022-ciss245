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
        : id_(id), anEngine_(3)
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
    Car aCar0(42);
    std::cout << "aCar0 starting engine in a clumsy way ...\n";
    aCar0.getEngine().start();
    
    Car aCar1(42);
    std::cout << "aCar1 starting engine in a cleaner way (by delegation) ...\n";
    aCar1.start();
    
    return 0;
}
