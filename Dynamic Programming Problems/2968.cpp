#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e9;
const int MAXN = (int)1e6 + 12345;

class Solution {
private:
    int n;
    vector<int> dp;
    enum Operation { none = 0, plus = 1, mult_by_2 = 2, mult_by_3 = 3 };
public:
    void read() {
        cin >> n;
    }
    string recover_answer(int n) {
        string answer = "";
        Operation operation = none;
        while(dp[n] != 0 && n >= 1) {
            int best_ans = INT_MAX;
            if (n % 3 == 0 && best_ans > dp[n / 3]) {
                best_ans = dp[n / 3];
                operation = mult_by_3; 
            }
            if (n % 2 == 0 && best_ans > dp[n / 2]) {
                best_ans = dp[n / 2];
                operation = mult_by_2; 
            }
            if (best_ans > dp[n - 1]) {
                best_ans = dp[n - 1];
                operation = plus; 
            }
            switch(operation) {
                case plus      : answer += to_string(plus);      n -= 1;  break;
                case mult_by_2 : answer += to_string(mult_by_2); n /= 2;  break;
                case mult_by_3 : answer += to_string(mult_by_3); n /= 3;  break;
                case none      : answer += to_string(none);               break;
            }
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
    
    string find_min_number_of_ops() {
        dp.resize(MAXN, INF);
        dp[1] = 0;
        for (int sum = 1; sum <= n; ++sum) {
            if (3 * sum <= n) { dp[3 * sum] = min(dp[3 * sum], dp[sum] + 1); }
            if (2 * sum <= n) { dp[2 * sum] = min(dp[2 * sum], dp[sum] + 1); }
            dp[1 + sum] = min(dp[1 + sum], dp[sum] + 1);
        }
        return recover_answer(n);
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
