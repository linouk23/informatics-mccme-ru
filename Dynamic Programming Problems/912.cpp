#include <bits/stdc++.h>

using namespace std;

const int MAXN = 41;

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
        // |{00, 10, 01, 11}| = 4
        dp[2] = 4;
        // |{000,  001,  010, 011, 100, 101, 110}| = 7
        dp[3] = 7;
        for (int index = 4; index <= n; ++index) {
            // ***0 -> ***0
            // **01 -> **01
            // **11 -> *011
            dp[index] = dp[index - 1] + dp[index - 2] + dp[index - 3];
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
