#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m;
    set<pair<int, int>> myset;
public:
    void read() {
        cin >> n >> m;
        
        int a, b;
        for (int edge = 0; edge < m; ++edge) {
            cin >> a >> b;
            --a; --b;
            myset.insert({min(a, b), max(a, b)});
        }
    }
    
    void solve() {
        for (int row = 0; row < n; ++row) {
            for (int column = row + 1; column < n; ++column) {
                if (!myset.count({row, column})) {
                    cout << "NO";
                    return;
                }
            }
        }
        cout << "YES";
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
