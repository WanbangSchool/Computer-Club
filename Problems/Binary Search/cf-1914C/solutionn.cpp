#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    // n: 퀘스트의 수, k: 최대 완료 가능한 퀘스트의 수
    long long n, k;
    cin >> n >> k;

    vector<long long> a(n);  // 처음 완료 시 얻는 경험치
    vector<long long> b(n);  // 반복 완료 시 얻는 경험치

    // 처음 완료 시 얻는 경험치 입력 받기
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 반복 완료 시 얻는 경험치 입력 받기
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    long long max_experience = 0;  // 최대 경험치 저장 변수
    long long first_complete_experience = 0;  // 첫 번째 완료 경험치의 합
    long long max_repeat_experience = 0;  // 반복 완료 시 최대 경험치

    // 최대 경험치를 계산하는 반복문
    for (int i = 0; i < n; i++) {
        if (i < k) {  // k보다 작은 경우, 첫 번째 완료 가능
            first_complete_experience += a[i];  // 첫 번째 완료 시 얻는 경험치 더하기
            max_repeat_experience = max(max_repeat_experience, b[i]);  // 반복 완료 시 최대 경험치 갱신
            // 최대 경험치 계산
            max_experience = max(max_experience, first_complete_experience + (k - i - 1) * max_repeat_experience);
        } else {
            break;  // 더 이상 퀘스트를 완료할 수 없으면 반복 종료
        }
    }

    cout << max_experience << endl;  // 최대 경험치 출력
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;  // 테스트 케이스 입력 받기

    // 각 테스트 케이스 처리
    for (int t = 0; t < test_cases; t++) {
        solve();
    }

    return 0;
}




/*
solve 함수: 각 테스트 케이스마다 퀘스트를 완료할 수 있는 최대 경험치를 계산하는 함수입니다.

a[] 배열: 각 퀘스트를 처음 완료할 때 얻는 경험치입니다.
b[] 배열: 각 퀘스트를 반복 완료할 때 얻는 경험치입니다.
first_complete_experience: 퀘스트를 처음 완료할 때 얻은 경험치의 합입니다.
max_repeat_experience: 반복 완료 시 최대 경험치를 추적합니다.
for 루프:

퀘스트를 처음 완료할 때 얻는 경험치를 더하고, 반복 완료 시 얻을 수 있는 최대 경험치를 계산합니다.
max_experience는 매번 최대 경험치를 갱신합니다.
main 함수:

test_cases라는 변수로 여러 테스트 케이스를 처리합니다.
각 테스트 케이스마다 solve() 함수를 호출하여 결과를 출력합니다.

first_complete_experience:

이 값은 첫 번째로 각 퀘스트를 완료했을 때 얻은 경험치의 합입니다.
퀘스트를 완료하는 순서대로 계속해서 경험치가 더해집니다.
(k - i - 1):

여기서 k는 총 완료할 수 있는 퀘스트의 수, i는 현재까지 완료한 퀘스트의 수를 나타냅니다.
k - i - 1은 앞으로 더 완료할 수 있는 퀘스트의 수를 나타냅니다. 즉, 현재 완료된 퀘스트를 제외하고 얼마나 더 완료할 수 있는지를 계산하는 식입니다.
max_repeat_experience:

반복 완료 시 얻을 수 있는 최대 경험치입니다. 첫 번째 완료 이후로 반복 완료할 때 얻는 추가 경험치 중 가장 높은 값을 유지하는 변수입니다.
k - i - 1 횟수만큼 반복 완료할 수 있으므로, 남은 횟수만큼 반복 완료를 해서 최대의 경험치를 얻는 상황을 계산하려는 것입니다.

*/