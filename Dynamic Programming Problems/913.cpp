#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;

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
        // |{0, 1}| = 2
        dp[1] = 2;
        // |{00, 10, 01}| = 3
        dp[2] = 3;
        for (int index = 3; index <= n; ++index) {
            // ***0 -> ***0
            // ***1 -> **01
            dp[index] = dp[index - 2] + dp[index - 1];
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
