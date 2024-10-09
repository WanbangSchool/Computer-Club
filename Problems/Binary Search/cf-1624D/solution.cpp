#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 전역 변수 선언
long long n, k;         // n: 문자열 길이, k: 그룹의 개수
string s;               // 주어진 문자열
long long pairCnt, oneCnt;  // 짝수 개수로 이루어진 문자 쌍과 홀수 개수 문자의 수

// 주어진 m 길이가 가능한지 확인하는 함수
bool isPossible(long long m) {
    // 필요한 짝수 쌍의 개수 계산
    long long reqPairCnt = k * (m / 2);

    // 필요한 짝수 쌍이 현재 짝수 쌍보다 많으면 불가능
    if (reqPairCnt > pairCnt)
        return false;

    // m이 홀수일 때
    if (m % 2 == 1) {
        // 남은 짝수 쌍을 2개의 홀수로 변환하여 사용
        long long totalOneCnt = oneCnt + ((pairCnt - reqPairCnt) * 2);

        // 필요한 홀수 개수가 현재 홀수 개수보다 많으면 불가능
        if (k > totalOneCnt)
            return false;
    }

    return true;
}

// 문제 해결 함수
void solve() {
    // 입력 받기
    cin >> n >> k >> s;

    // 만약 그룹의 개수가 문자열 길이와 같다면, 답은 1
    if (k == n) {
        cout << 1;
        return;
    }

    vector<long long> freq(26, 0);  // 각 문자의 빈도 저장 (알파벳 소문자)
    pairCnt = 0;  // 짝수 쌍의 개수
    oneCnt = 0;   // 홀수 개수 문자의 개수

    // 각 문자의 빈도 계산
    for (long long i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    // 짝수 쌍과 홀수 개수 계산
    for (long long i = 0; i < 26; i++) {
        pairCnt += (freq[i] / 2);  // 짝수 쌍
        oneCnt += (freq[i] % 2);   // 홀수 개수
    }

    long long lo = 1, hi = n, ans = 1;  // 이분 탐색 변수

    // 이분 탐색으로 최대 가능한 그룹 크기 찾기
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;

        // mid 길이가 가능한지 확인
        if (isPossible(mid)) {
            ans = mid;
            lo = mid + 1;  // 더 큰 길이 시도
        } else {
            hi = mid - 1;  // 더 작은 길이 시도
        }
    }

    // 답 출력
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);  // 입력 속도 향상
    cin.tie(0);  // 출력 속도 향상

    long long tc;  // 테스트 케이스 개수
    cin >> tc;

    // 각 테스트 케이스 해결
    while (tc--) {
        solve();
        cout << '\n';  // 각 테스트 케이스 후 줄바꿈
    }

    return 0;
}



/*
입력 변수:

n은 문자열의 길이, k는 그룹의 개수, s는 입력 문자열입니다.
pairCnt는 짝수 개수로 쌍을 이룰 수 있는 문자 개수, oneCnt는 홀수 개수 문자의 수입니다.
isPossible 함수:
이 함수는 주어진 길이 m이 가능한지 확인합니다.

짝수 쌍(pairCnt)이 충분한지 확인하고, m이 홀수일 경우 남은 짝수 문자를 두 개씩 묶어 홀수로 전환하여 사용할 수 있는지 판단합니다.
이분 탐색을 이용한 최대 그룹 길이 찾기:
solve() 함수에서 이분 탐색을 사용해 1부터 n까지의 길이 중 가능한 최대 길이를 찾습니다. mid 길이가 가능한지 확인한 후, 가능하면 더 큰 길이를 시도하고, 불가능하면 더 작은 길이를 시도합니다.

최종 출력:
각 테스트 케이스에 대해 최대 가능한 그룹 길이를 출력합니다.
*/