#include <bits/stdc++.h>

using namespace std;

// const int MAXN = 123456;

class Solution {
private:
    vector<vector<int>> g;
    int n;
    vector<bool> used;
public:
    void read() {
        cin >> n;
        used.resize(n, false);
        g.resize(n, vector<int>(n));
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                cin >> g[row][column];
            }
        }
    }
    
    void dfs(int vertex) {
        used[vertex] = true;
        for (int neigbour = 0; neigbour < n; ++neigbour) {
            if (g[vertex][neigbour] && !used[neigbour]) {
                dfs(neigbour);
            }
        }
    }
    
    bool is_connected() {
        for (int vertex = 0; vertex < n; ++vertex) {
            if (!used[vertex]) {
                return false;
            }
        }
        return true;
    }
    
    void solve() {
        dfs(0);
        
        if (!is_connected()) {
            cout << "NO";
            return;
        }
        
        int answer = 0;
        for (int v1 = 0; v1 < n; ++v1) {
            for (int v2 = 0; v2 < n; ++v2) {
                if (g[v1][v2]) {
                    ++answer;
                }
            }
        }
        if (answer / 2 == (n - 1)) {
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
