#include <bits/stdc++.h>

using namespace std;

const int MAXN = 123456;

class Solution {
private:
    int n, m;
    vector<int> g[MAXN];
public:
    void read() {
        cin >> n >> m;
        int a, b;
        for (int edge = 0; edge < m; ++edge) {
            cin >> a >> b;
            --a; --b;
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
    }
    
    void solve() {
        for (int vertex = 0; vertex < n; ++vertex) {
            cout << (int)g[vertex].size() << endl;
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
