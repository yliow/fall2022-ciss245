#include <iostream>

int dist(int x[], int n, int i)
{
    // computer tot dist travelled to x[i]
    int s = 0;
    for (int j = 0; j < n; ++j)
    {
        int d = x[i] - x[j];
        d = (d >= 0 ? d : -d);
        s += d;
        //std::cout << d << ' ' << s << '\n';
    }
    std::cout << i << ' ' << s << '\n';
    return s;
}

int main()
{
    int x[6] = {5, 3, 2, 7, 8, 3};
    int n = 6;

    int min_s;
    int min_index;

    min_s = dist(x, n, 0);
    min_index = 0;
    
    for (int i = 1; i < n; ++i) // x[i] is party house
    {
        int s = dist(x, n, i);
        if (s < min_s)
        {
            min_s = s;
            min_index = i;
        }
        std::cout << i << ' ' << s << ' ' << min_s << ' ' << min_index << '\n';        
    }

    return 0;
}
