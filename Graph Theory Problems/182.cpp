#include "bits/stdc++.h"

using namespace std;

// const int MAXN = 123456;

class Solution {
private:
    int n, m;
    vector<vector<int> > g;
    vector<bool> visited;
public:
    void read() {
        cin >> n >> m;
        visited.resize(n, false);
        g.resize(n);
        int start, finish;
        for (int edge = 0; edge < m; ++edge) {
            cin >> start >> finish;
            --start; --finish;
            g[start].emplace_back(finish);
            g[finish].emplace_back(start);
        }
    }
    
    void dfs(int v, int prev = -1) {
        if (prev != -1) {
            cout << prev + 1 << " " << v + 1 << endl;
        }
        
        visited[v] = true;
        for (int neighbour : g[v]) {
            if (!visited[neighbour]) {
                dfs(neighbour, v);
            }
        }
    }
    
    void solve() {
        dfs(0);
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
