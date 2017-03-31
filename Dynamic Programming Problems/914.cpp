#include <bits/stdc++.h>

using namespace std;

const int MAXN = 123;

class Solution {
private:
    int n;
public:
    void read() {
        cin >> n;
    }
    int get_nth() {
        vector<int> dp(MAXN);
        dp[0] = 0;
        // |{0, 1, 2}| = 3
        dp[1] = 3;
        // |{00, 01, 02, 10, 11, 12, 20, 21}| = 8
        dp[2] = 8;
        for (int index = 3; index <= n; ++index) {
            // ***0 -> ***0
            // ***1 -> ***1
            // ***2 -> **02
            // ***2 -> **12
            dp[index] = 2 * (dp[index - 1] + dp[index - 2]);
        }
        return dp[n];
    }
};

int main() {
    ios::sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);

    Solution solution;
    solution.read();
    cout << solution.get_nth();

    return 0;
}
