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
            myset.insert({a, b});
            myset.insert({b, a});
        }
    }
    
    void solve() {
        if (myset.size() == n * (n - 1)) {
            cout << "YES";
        } else {
            cout << "NO";
        }
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
