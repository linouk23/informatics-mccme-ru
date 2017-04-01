#include <bits/stdc++.h>

using namespace std;

struct Vertex {
    int row, column;
    Vertex(int row, int column) : row(row), column(column) {}

    bool operator !=(const Vertex & op) const {
        return row != op.row || column != op.column;
    }
};

class Solution {
private:
    int n, m;
    const int num_of_steps = 8;
    vector<vector<int>> matrix;
    int st_row, st_col, fin_row, fin_col;
    vector<vector<bool>> visited;
    vector<vector<Vertex>> prev;
    vector<int> dx = {2, 2, 1, 1, -1, -1, -2, -2};
    vector<int> dy = {1,-1, 2, -2, 2, -2, 1, -1};
public:
    void read() {
        cin >> n;
        m = n;
        visited.resize(n, vector<bool> (m, false));
        prev.resize(n, vector<Vertex> (m, Vertex(-1, -1)));
        cin >> st_col >> st_row;
        cin >> fin_col >> fin_row;
        --st_row; --st_col;
        --fin_row; --fin_col;
    }

    bool is_in_board(const Vertex &p) {
        return (p.row >= 0) && (p.row < n) &&
               (p.column >= 0) && (p.column < m);
    }
    
    void solve() {
        queue<Vertex> q;
        Vertex start(st_row, st_col);
        q.push(start);
        visited[start.row][start.column] = true;
        while(!q.empty()) {
            Vertex v = q.front(); q.pop();
            for (int step = 0; step < num_of_steps; ++step) {
                Vertex neighbour(v.row + dy[step], v.column + dx[step]);
                if (is_in_board(neighbour) && 
                    !visited[neighbour.row][neighbour.column]) {
                    visited[neighbour.row][neighbour.column] = true;
                    q.push(neighbour);
                    prev[neighbour.row][neighbour.column] = v;
                }
            }
        }
        Vertex last_vertex(fin_row, fin_col);
        vector<Vertex> path;
        Vertex fake_vertex(-1, -1);
        while(last_vertex != fake_vertex) {
            path.emplace_back(last_vertex);
            last_vertex = prev[last_vertex.row][last_vertex.column];
        }
        reverse(path.begin(), path.end());
        cout << (int)path.size() - 1 << endl;
        for (const auto & p : path) {
            cout << p.column + 1 << " " << p.row + 1 << endl;
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
