#include <iostream>

int mystrlen(char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        ++i;
    }
    return i;
}

void debug(char s[])
{
    for (int i = 0; i < mystrlen(s); ++i)
    {
        std::cout << '(' << s[i] << ',' << int(s[i]) << ')' << ' ';
    }
    std::cout << '\n';
}

int main()
{
    char s[1024] = "abc";
    std::cout << '[' << s << ']' << '\n';
    char t[1024] = "defghi";
    std::cout << '[' << t << ']' << '\n';

    debug(s);
    std::cout << mystrlen(s) << '\n';
    return 0;
}
