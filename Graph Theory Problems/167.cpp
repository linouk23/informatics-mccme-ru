#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
    vector<pair<int, int>> arr;
public:
    void read() {
        cin >> n;
        int a, b;
        for (int index = 0; index < n; ++index) {
            cin >> a >> b;
            if (b) { arr.emplace_back(a, index + 1); }
        }
    }

    void solve() {
        if (arr.empty()) {
            cout << -1;
            return;
        }
        int max_num = INT_MIN;
        int answer = -1;
        for (const auto & p : arr) {
            if (p.first > max_num) {
                max_num = p.first;
                answer = p.second;
            }
        }
        cout << answer;
    }
};

int main() {
    ios::sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);

    Solution solution;
    solution.read();
    solution.solve();

    return 0;
}
