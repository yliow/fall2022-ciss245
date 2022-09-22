#include <iostream>
#include <fstream>

int mystrlen(char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        ++i;
    }
    return i;
}

//            6 is returned
//            v
// s = "abcdefghijkl"
// t = "ghi"
//      "ghi"
//       "ghi"
//              "ghi"         
int find(char s[], char target[])
{
    for (int i = 0; i <= mystrlen(s) - mystrlen(target); ++i)
    {
        bool found = true;
        for (int j = 0; j < mystrlen(t); ++j)
        {
            if (s[i + j] != t[j])
            {
                found = false;
                break;
            }
        }
        if (found) return i;
    }
    return -1;
}

int main()
{
    std::ifstream f("1661-0.txt", std::ios::in);
    char s[700000];

    int i = 0;
    while (f.get(s[i]))
    {
        ++i;
    }
    std::cout << s << '\n';

    char title[] = "Title: ";
    int index = find(s, title);
    
    return 0;
}
