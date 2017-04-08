#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int num_of_rows, num_of_cols, n;
    vector<vector<int> > g;
    vector<int> prev;
    const int INF = (int)1e9;
    int white, black, gray;
public:
    int get_num(int row, int column) {
        return row * num_of_cols + column + 1;
    }
    
    void read() {
        
        cin >> num_of_rows >> num_of_cols >> white >> black >> gray;
        n = num_of_rows * num_of_cols + 2;
        g.resize(n, vector<int> (n, 0));
        int source = 0;
        int sink = n - 1;
        string str;
        for (int row = 0; row < num_of_rows; ++row) {
            cin >> str;
            for (int column = 0; column < num_of_cols; ++column) {
                if (str[column] == 'W') {
                    g[get_num(row, column)][sink] += black;
                } else {
                    g[source][get_num(row, column)] += white;
                }
                if (row < num_of_rows - 1) {
                    g[get_num(row, column)][get_num(row + 1, column)] += gray;
                    g[get_num(row + 1, column)][get_num(row, column)] += gray;
                }
                if (column < num_of_cols - 1) {
                    g[get_num(row, column)][get_num(row, column + 1)] += gray;
                    g[get_num(row, column + 1)][get_num(row, column)] += gray;
                }
            }
        }
    }
    
    bool bfs(int source, int sink, int min_capacity) {
        prev.assign(n, -1);
        queue<int> q;
        q.push(source);
        vector<bool> visited(n, false);
        visited[source] = true;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for (int neighbour = 0; neighbour < n; ++neighbour) {
                if (!visited[neighbour] && g[cur][neighbour] >= min_capacity) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                    prev[neighbour] = cur;
                }
            }
        }
        return visited[sink];
    }
    
    vector<int> get_path(int sink) {
        vector<int> path;
        while(sink != -1) {
            path.emplace_back(sink);
            sink = prev[sink];
        }
        reverse(path.begin(), path.end());
        return path;
    }
    
    int get_min_flow(vector<int> &path) {
        int path_flow = INF;
        for (int index = 0; index < (int)path.size() - 1; ++index) {
            int from = path[index];
            int to = path[index + 1];
            path_flow = min(path_flow, g[from][to]);
        }
        return path_flow;
    }
    
    void update_matrix(vector<int> &path, int path_flow) {
        for (int index = 0; index < (int)path.size() - 1; ++index) {
            int from = path[index];
            int to = path[index + 1];
            g[from][to] -= path_flow;
            g[to][from] += path_flow;
        }
    }
    
    void solve() {
        int source = 0;
        int sink = n - 1;
        int max_flow = 0;
        
        double max_weight = 1.0 * max({black, white, gray});
        int capacity_to_find = (1 << ((int)(log2(max_weight))));
        
        while(capacity_to_find >= 1) {
            while(bfs(source, sink, capacity_to_find)) {
                vector<int> path = get_path(sink);
                int path_flow = get_min_flow(path);
                max_flow += path_flow;
                update_matrix(path, path_flow);
            }
            capacity_to_find >>= 1;
        }
        cout << max_flow;
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
