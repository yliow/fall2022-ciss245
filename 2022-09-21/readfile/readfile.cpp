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
        for (int j = 0; j < mystrlen(target); ++j)
        {
            if (s[i + j] != target[j])
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
    int index0 = find(s, title);
    // print first 20 characters after title is found
    for (int i = index0 + 7; i < index0 + 27; ++i)
    {
        std::cout << s[i];
    }
    std::cout << '\n';
    
    return 0;
}
