#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e9;
const int MAXN = (int)1e6 + 12345;

class Solution {
private:
    vector<int> dp;
    int n;
public:
    void read() {
        cin >> n;
    }
    int find_min_number_of_ops() {
        dp.resize(MAXN, INF);
        dp[1] = 0;
        for (int sum = 1; sum <= n; ++sum) {
            if (3 * sum <= n) { dp[3 * sum] = min(dp[3 * sum], dp[sum] + 1); }
            if (2 * sum <= n) { dp[2 * sum] = min(dp[2 * sum], dp[sum] + 1); }
            dp[1 + sum] = min(dp[1 + sum], dp[sum] + 1);
        }
        return dp[n];
    }
};

int main() {
    ios::sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);

    Solution solution;
    solution.read();
    cout << solution.find_min_number_of_ops();

    return 0;
}
