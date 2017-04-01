#include <bits/stdc++.h>

using namespace std;

struct Vertex {
    int row, column;
    Vertex(int row, int column) : row(row), column(column) {}
};

class Solution {
private:
    int n, m;
    const int num_of_steps = 4;
    vector<vector<int>> matrix;
    vector<vector<int>> dist;
    vector<vector<bool>> visited;
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};
public:
    void read() {
        cin >> n >> m;
        visited.resize(n, vector<bool> (m, false));
        dist.resize(n, vector<int> (m, 0));
        matrix.resize(n, vector<int> (m));
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < m; ++column) {
                cin >> matrix[row][column];
            }
        }
    }

    bool is_in_board(const Vertex &p) {
        return (p.row >= 0) && (p.row < n) &&
               (p.column >= 0) && (p.column < m);
    }
    
    void solve() {
        queue<Vertex> q;
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < m; ++column) {
                if (matrix[row][column]) {
                    q.push(Vertex(row, column));
                    visited[row][column] = true;
                }
            }
        }
        
        while(!q.empty()) {
            Vertex v = q.front(); q.pop();
            for (int step = 0; step < num_of_steps; ++step) {
                auto p = Vertex(v.row + dy[step], v.column + dx[step]);
                if (is_in_board(p) && 
                    !visited[p.row][p.column]) {
                    visited[p.row][p.column] = true;
                    q.push(p);
                    dist[p.row][p.column] = dist[v.row][v.column] + 1;
                }
            }
        }
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < m; ++column) {
                cout << dist[row][column] << " ";
            }
            cout << endl;
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
