#include "bits/stdc++.h"

using namespace std;

struct Vertex {
    int row, column;
    
    Vertex() {}
    Vertex(int row, int column) :
    row(row), column(column) {}
    
    bool operator ==(const Vertex& op) const {
        return (row == op.row) && (column == op.column);
    }
    
    bool operator <(const Vertex& op) const {
        if (row != op.row) {
            return row < op.row;
        }
        
        return column < op.column;
    }
};

class Solution {
private:
    int n, m, k, x, y;
    vector<string> g;
    vector<Vertex> starts;
public:
    void read() {
        cin >> n >> m;
        g.assign(n, string(m, '0'));
        string str;
        getline(cin, str);
        for (int row = 0; row < n; ++row) {
            getline(cin, g[row]);
        }
        cin >> k;
        for (int start = 0; start < k; ++start) {
            cin >> x >> y;
            --x; --y;
            starts.emplace_back(x, y);
        }
    }
    
    bool is_in_field(const Vertex & v) {
        return v.row < n && v.row >= 0 && v.column < m && v.column >= 0;
    }
    
    bool is_wall(const Vertex & v) {
        return g[v.row][v.column] == '1';
    }
    
    void solve() {
        queue<Vertex> q;
        set<Vertex> visited;
        map<Vertex, Vertex> prev;
        map<Vertex, Vertex> start_vertex;
        
        Vertex finish(-1, -1);
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < m; ++column) {
                if (g[row][column] == '*') {
                    finish.row = row;
                    finish.column = column;
                }
            }
        }

        if (finish.row == -1) {
            cout << -1;
            return;
        }
        
        vector<int> dx = {0, 0,  -1, 1};
        vector<int> dy = {1, -1, 0,  0};
        
        for (const Vertex & v : starts) {
            q.push(v);
            visited.insert(v);
            prev[v] = v;
            start_vertex[v] = v;
        }
        
        while(!q.empty()) {
            Vertex cur = q.front(); q.pop();
            for (int edge = 0; edge < 4; ++edge) {
                Vertex neighbour(cur.row + dy[edge], cur.column + dx[edge]);
                if (!visited.count(neighbour) && is_in_field(neighbour) && !is_wall(neighbour)) {
                    q.push(neighbour);
                    visited.insert(neighbour);
                    prev[neighbour] = cur;
                    start_vertex[neighbour] = start_vertex[cur];
                }
            }
        }
        
        if (!start_vertex.count(finish)) {
            cout << -1;
            return;
        }

        for (int index = 0; index < (int)starts.size(); ++index) {
            if (starts[index] == start_vertex[finish]) {
                cout << index + 1;
                return;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    
//    freopen("input.txt", "r", stdin);
    
    Solution solution;
    solution.read();
    solution.solve();
    
    return 0;
}
