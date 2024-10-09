int N;

struct Point {
    int x;
    int y;
    bool disable;
};

vector<Point> cows;
// vector<Point> chosen;

int find(int one, int two, int three) {

    int minX = INT_MAX, maxX = INT_MIN;
    int minY = INT_MAX, maxY = INT_MIN;


    F0R(i, N) {
        if (i != one && i != two && i != three) {
            minX = min(minX, cows[i].x);
            maxX = max(maxX, cows[i].x);
            minY = min(minY, cows[i].y);
            maxY = max(maxY, cows[i].y);
        }
    }

    return (maxX - minX) * (maxY - minY);
}


bool valid(int i) {
    int sum = 0;
    while (i) {
        sum += i & 1;
        i = i >> 1;
    }
    return sum == 3;
}

vector<vector<int>> combinations(int num) {
    vector<vector<int>> ans;

    F0R(i, pow(2, num)) {
        if (valid(i)) {
            //dbg(bitset<12>(i));
            vector<int> x;
            int k = i;
            F0R(j, num) {
                if (k & 1) {
                    x.push_back(j);
                }
                k = k >> 1;
            }
            ans.push_back(x);
        }
    }
    dbg(ans.size());
    return ans;
}


int main() {
    ifstream cin("reduce.in");
    ofstream cout("reduce.out");

    cin >> N;

    cows.resize(N);

    F0R(i, N) {
        cin >> cows[i].x >> cows[i].y;
    }

    sort(cows.begin(), cows.end(), [](Point a, Point b) {return a.x < b.x;});

    cows[0].disable = true;
    cows[1].disable = true;
    cows[2].disable = true;

    cows[N - 1].disable = true;
    cows[N - 2].disable = true;
    cows[N - 3].disable = true;


    sort(cows.begin(), cows.end(), [](Point a, Point b) {return a.y < b.y;});

    cows[0].disable = true;
    cows[1].disable = true;
    cows[2].disable = true;

    cows[N - 1].disable = true;
    cows[N - 2].disable = true;
    cows[N - 3].disable = true;

    vector<int> chosen;

    F0R(i, cows.size()) {
        if (cows[i].disable) {
            chosen.push_back(i);
        }
    }


    dbg(chosen);

    vector<vector<int>> myVec = combinations(chosen.size());

    int ans = INT_MAX;


    for(auto choice : myVec) {
        int area = find(chosen[choice[0]], chosen[choice[1]], chosen[choice[2]]);
        dbg(choice, chosen[choice[0]], chosen[choice[1]], chosen[choice[2]], area);
        ans = min(ans, area);
    }

    cout << ans;
}