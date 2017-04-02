#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<string> g;
    vector<bool> used;
    int n, m;
public:
    void read() {
        cin >> n >> m;
        used.resize(n * m, false);
        g.resize(n);
        for (int line = 0; line < n; ++line) {
            cin >> g[line];
        }
    }

    void dfs(int row, int column) {
        if (row < 0 || column < 0 || row >= n || column >= m) { return; }
        if (g[row][column] == '.')  { return; }
        if (used[row * m + column]) { return; }
        used[row * m + column] = true;
        dfs(row + 1, column);
        dfs(row - 1, column);
        dfs(row, column + 1);
        dfs(row, column - 1);
    }

    int find_num_of_comps() {
        int answer = 0;
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < m; ++column) {
                if (!used[row * m + column] && g[row][column] == '#') {
                    dfs(row, column);
                    ++answer;
                }
            }
        }
        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);

    Solution solution;
    solution.read();
    cout << solution.find_num_of_comps();

    return 0;
}
