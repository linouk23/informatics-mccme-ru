#include <bits/stdc++.h>

using namespace std;

const int MAXN = 123;

class Solution {
private:
    int n;
    vector<int> prices;
public:
    void read() {
        cin >> n;
        prices.resize(n + 1);
        for (int index = 1; index <= n; ++index) {
            cin >> prices[index];
        }
    }
    
    int get_nth() {
        vector<int> dp(MAXN);
        dp[0] = 0;
        dp[1] = prices[1];
        dp[2] = min(dp[1] + prices[2], prices[2]);
        
        for (int index = 3; index <= n; ++index) {
            dp[index] = min(dp[index - 1], dp[index - 2]) + prices[index];
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
