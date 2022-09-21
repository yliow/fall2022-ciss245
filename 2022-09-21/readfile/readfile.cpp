#include <iostream>
#include <fstream>

int main()
{
    std::ifstream f("/home/student/Downloads/1661-0.txt", std::ios::in);
    char s[700000];

    int i = 0;
    while (f.get(s[i]))
    {
        ++i;
    }
    std::cout << s << '\n';    
    return 0;
}
