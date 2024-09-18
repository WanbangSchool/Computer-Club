#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        
        // 6조각 이상의 피자가 필요한지 여부에 따라 계산
        long long result;
        if (n <= 6) result = 15;
        else if (n <= 8) result = 20;
        else if (n <= 10) result = 25;
        else result = (n + 1) / 2 * 5; // 10조각당 25분, 2조각당 5분
        cout << result << endl;
    }
    return 0;
}
