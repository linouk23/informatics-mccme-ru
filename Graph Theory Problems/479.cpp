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
        for (int v1 = 0; v1 < n; ++v1) {
            for (int v2 = v1 + 1; v2 < n; ++v2) {
                for (int v3 = v2 + 1; v3 < n; ++v3) {
                    vector<int> v = {(int)myset.count({v1, v2}), (int)myset.count({v2, v3}), (int)myset.count({v1, v3})};
                    int sum = 0;
                    for (int el : v) {
                        sum += el;
                    }
                    if (sum == 2) {
                        cout << "NO";
                        return;
                    }
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
