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
        vector<int> seq(n + 1);
        seq[0] = seq[1] = 1;
        for (int index = 2; index <= n; ++index) {
            if (index % 2) {
                seq[index] = seq[(index + 1) / 2] + 1 + seq[(index + 1) / 2 - 1] ;
            } else {
                seq[index] = seq[index / 2] + 1;
            }
        }
        return seq[n];
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
