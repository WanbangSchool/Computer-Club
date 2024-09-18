#include <bits/stdc++.h>
using namespace std;


long long square(long long a, long long b) {
long long res=1;
for (long long i=0; i<b; i++) {
    res=res*a;
}

return res;
}

int main()
{
    deque<long long> ssuumm;

    ssuumm.push_back(0);

    long long n, cnt=1;
    cin >> n;
    long long nn = n;
    while (n>9) {
        n = n/10;
        cnt++;
    }


    n = nn;
        long long sb;

    for (long long i=n; i>=0; i--) {
        for (nn=i, sb=0; nn!=0;) {
            sb += nn%10;
            nn /= 10;
        }

        if ( n == i+sb) {
            ssuumm.push_back(i);
        }
    }

    sort(ssuumm.begin(), ssuumm.end());
    if(ssuumm.size()!=1) {
        ssuumm.pop_front();
    }


    cout << ssuumm[0];

    return 0;
}


