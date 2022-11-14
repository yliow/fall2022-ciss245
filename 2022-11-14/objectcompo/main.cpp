#include <iostream>

class Bag
{
};

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
