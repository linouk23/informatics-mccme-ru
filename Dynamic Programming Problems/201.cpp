#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
public:
    void read() {
        cin >> n;
    }
    int get_nth() {
        vector<int> fib(n + 1);
        fib[0] = 0;
        fib[1] = fib[2] = 1;
        for (int index = 3; index <= n; ++index) {
            fib[index] = fib[index - 1] + fib[index - 2];
        }
        return fib[n];
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
