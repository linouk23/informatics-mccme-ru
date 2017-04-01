#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
    vector<vector<int>> matrix;
    int start, finish;
    vector<bool> visited;
    vector<int> prev;
public:
    void read() {
        cin >> n;
        matrix.resize(n, vector<int> (n));
        visited.resize(n, false);
        prev.resize(n);
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                cin >> matrix[row][column];
            }
        }
        cin >> start >> finish;
        --start; --finish;
    }
    
    void solve() {
        queue<int> q;
        q.push(start);
        visited[start] = true;
        prev[start] = -1;
        while(!q.empty()) {
            int v = q.front(); q.pop();
            for (int neighbour = 0; neighbour < n; ++neighbour) {
                if (matrix[v][neighbour]) {
                    if (!visited[neighbour]) {
                        visited[neighbour] = true;
                        prev[neighbour] = v;
                        q.push(neighbour);
                    }
                }
            }
        }
        if (!visited[finish]) {
            cout << -1;
        } else {
            vector<int> path;
            int last_vertex = finish;
            while(last_vertex != -1) {
                path.emplace_back(last_vertex);
                last_vertex = prev[last_vertex];
            }
            cout << (int)path.size() - 1 << endl;
            if ((int)path.size() - 1) {
                reverse(path.begin(), path.end());
                for (int v : path) {
                    cout << v + 1 << " ";
                }
            }
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
