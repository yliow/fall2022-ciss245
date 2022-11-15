#include <iostream>

class Book
{
public:
    Book(int id)
        : id_(id)
    {}
    int id() const
    {
        return id_;
    }
private:
    int id_;
};
std::ostream & operator<<(std::ostream & cout, const Book & book)
{
    cout << "<Book " << book.id() << '>';
    return cout;
}

class Bag
{
public:
    Bag()
        : size_(0), capacity_(3)
    {}
    int size() const 
    {
        return size_;
    }
    Book * operator[](int i) const
    {
        return pbook[i];
    }
private:
    int size_;
    int capacity_;
    Book * pbook[3];
};

std::ostream & operator<<(std::ostream & cout, const Bag & bag)
{
    cout << "<Bag\n";
    for (int i = 0; i < bag.size(); ++i)
    {
        cout << (*(bag[i])) << '\n';
    }
    cout << ">";
    return cout;
}

int main()
{
    Book b0(0);
    Book b1(1);
    Book b2(2);

    std::cout << "my books ...\n";
    std::cout << b0 << '\n';
    std::cout << b1 << '\n';
    std::cout << b2 << '\n';
    
    return 0;
}
