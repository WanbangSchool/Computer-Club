/*o(n log n)*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;  // 테스트 케이스 수 입력

    while (t--) {
        int n, k;
        cin >> n >> k;  // 퀘스트 수와 최대 완료 가능한 퀘스트 수 입력

        vector<int> a(n), b(n);

        // 배열 a와 b 입력 받기
        for (int i = 0; i < n; i++) cin >> a[i];  // 첫 번째 완료 보상
        for (int i = 0; i < n; i++) cin >> b[i];  // 이후 완료 보상

        // 각 퀘스트의 첫 번째 완료 보상과 이후 완료 보상을 저장할 벡터
        vector<pair<int, int>> quests;

        // 각 퀘스트의 보상 정보를 벡터에 추가
        for (int i = 0; i < n; i++) {
            quests.push_back({a[i], b[i]});
        }

        // 첫 번째 완료 보상을 기준으로 퀘스트를 정렬
        sort(quests.begin(), quests.end());

        // 총 경험치 계산을 위한 변수
        long long total_experience = 0;

        // 이후 완료 보상을 저장할 벡터
        vector<int> completions;

        // 먼저 각 퀘스트를 최소 한 번씩 완료
        for (int i = 0; i < n && i < k; i++) {
            total_experience += quests[i].first;  // 첫 번째 완료 보상 추가
            completions.push_back(quests[i].second);  // 이후 완료 보상 저장
        }

        // 이후 완료 보상을 내림차순으로 정렬
        sort(completions.rbegin(), completions.rend());

        // 남은 횟수만큼 이후 완료 보상으로 퀘스트 완료
        for (int i = 0; i < completions.size() && i + n < k; i++) {
            total_experience += completions[i];
        }

        // 현재 테스트 케이스의 결과 출력
        cout << total_experience << endl;
    }

    return 0;
}



/*
이 문제는 Monocarp가 제한된 시간 동안 주어진 퀘스트를 최대한 많이 완료하여 얻을 수 있는 총 경험치를 최대화하는 문제입니다. 각 퀘스트는 첫 번째 완료 시 더 많은 경험치를 주고, 그 이후에 완료할 때는 적은 경험치를 제공합니다.

문제 접근 방법
1. 퀘스트 완료 규칙
첫 번째 완료: 각 퀘스트는 처음 완료할 때 더 많은 경험치 a[i]를 줍니다.
이후 완료: 이후 같은 퀘스트를 완료할 때는 적은 경험치 b[i]를 줍니다.
따라서, 최대한 효율적으로 퀘스트를 완료하여 경험치를 많이 얻는 것이 목표입니다.

2. 문제 해결 전략
퀘스트 완료 순서:

첫 번째로 각 퀘스트를 한 번씩 완료하면 최대한 많은 첫 번째 완료 보상(a[i])을 얻을 수 있습니다.
그 후 남은 퀘스트 완료 횟수를 이용하여 각 퀘스트를 반복 완료하여 그 이후 보상(b[i])을 더 얻을 수 있습니다.
효율적인 보상 관리:

각 퀘스트의 첫 번째 완료 보상과 이후 완료 보상을 모두 고려하여 가장 경험치를 많이 주는 퀘스트부터 우선적으로 완료해야 합니다.
이를 위해 첫 번째 완료 보상과 이후 완료 보상을 정리하여 최적의 퀘스트 완료 순서를 결정합니다.

3. 문제 풀이 단계
첫 번째 완료 처리:

먼저 모든 퀘스트를 한 번씩 완료하고, 첫 번째 완료 보상 a[i]를 얻습니다.
첫 번째 완료한 후, 남은 시간 내에서 각 퀘스트를 반복 완료하여 추가 경험치를 얻습니다.
남은 시간 최대 활용:

첫 번째 완료 이후 남은 횟수만큼 경험치를 최대화하기 위해, 각 퀘스트의 이후 완료 보상 b[i]를 이용하여 더 많은 보상을 얻도록 반복 완료합니다.
남은 퀘스트의 보상을 정렬하여, 보상이 높은 퀘스트부터 반복 완료합니다.
4. 최종 풀이 로직
퀘스트의 보상 정보를 저장한 후, 첫 번째 완료 시 최대한 많은 경험치를 얻습니다.
그 후 남은 횟수만큼 퀘스트를 반복 완료하여 최대한 많은 추가 보상을 얻습니다.
최대 경험치를 출력합니다.
최종 알고리즘
첫 번째로 각 퀘스트를 한 번씩 완료하여 최대한 많은 첫 번째 완료 보상을 얻는다.
이후 반복 완료를 통해 경험치를 추가로 얻는다.
경험치를 얻는 순서를 결정하기 위해 보상 정보를 정리하고, 효율적으로 퀘스트를 완료한다.


코드 설명:
입력 받기:

t: 테스트 케이스의 수를 입력받습니다.
각 테스트 케이스마다 n과 k를 입력받습니다.
각 퀘스트의 첫 번째 완료 보상 a[i]와 이후 완료 보상 b[i]를 입력받습니다.
퀘스트 정보 저장:

각 퀘스트의 첫 번째 완료 보상과 이후 완료 보상을 pair로 묶어 벡터 quests에 저장합니다.
퀘스트 정렬:

첫 번째 완료 보상 a[i]를 기준으로 퀘스트를 오름차순으로 정렬합니다. 이는 더 낮은 보상의 퀘스트를 먼저 완료하기 위함입니다.
퀘스트 완료 시뮬레이션:

첫 번째 완료: 가능한 한 모든 퀘스트를 한 번씩 완료하여 첫 번째 완료 보상을 획득합니다.
총 k번의 완료 기회 중 n번을 사용하여 각 퀘스트를 한 번씩 완료합니다.
각 퀘스트의 이후 완료 보상 b[i]를 벡터 completions에 저장합니다.
이후 완료: 남은 완료 기회(k - n)만큼 이후 완료 보상이 높은 퀘스트를 반복 완료합니다.
completions 벡터를 내림차순으로 정렬하여 이후 완료 보상이 높은 순서대로 선택합니다.
남은 횟수만큼 총 경험치에 이후 완료 보상을 더합니다.
결과 출력:

각 테스트 케이스마다 계산된 총 경험치를 출력합니다.
시간 복잡도:
각 테스트 케이스마다 최대 O(n log n)의 시간 복잡도를 가집니다.
전체 시간 복잡도는 O(t * n log n)이며, 주어진 제약 조건 내에서 효율적으로 동작합니다.*/