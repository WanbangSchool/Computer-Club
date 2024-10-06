#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 12;
    int array[12] = {1, 3, 3, 4, 5, 5, 6, 9, 10, 12, 12, 15};

    int k = 0;
    for (int b = n / 2; b >= 1; b /= 2)
    {
        while (k + b < n && array[k + b] <= 9)
            k += b;
    }
    if (array[k] == 9)
    {
        cout << k;
    }
}


 
