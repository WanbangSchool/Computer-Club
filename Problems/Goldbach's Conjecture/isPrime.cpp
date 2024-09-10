#include <bits/stdc++.h>
using namespace std;
/*bool prime(int n)
{
    if (n < 2)
        return false;

    for (int x = 2; x * x <= n; x++)
    {
        if (n % x == 0)
            return false;
    }

    return true;
} */

int main()
{
    vector<bool> sieve = {0};
    int n = 3994;
    for (int x=2; x<=n; x++) {
        if (sieve[x]) continue;
        for (int u = 2*x; u<=n; u += x) {
            sieve[u] = 1;
        }
    }
}