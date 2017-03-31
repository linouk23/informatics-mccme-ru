#include <bits/stdc++.h>

using namespace std;

const int MAXN = 40;

class Solution {
private:
    int n;
public:
    void read() {
        cin >> n;
    }
    int get_nth() {
        vector<int> fib(MAXN);
        fib[0] = 0;
        fib[1] = 1;
        fib[2] = 2;
        fib[3] = 4;
        for (int index = 4; index <= n; ++index) {
            fib[index] = fib[index - 1] + fib[index - 2] + fib[index - 3];
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
