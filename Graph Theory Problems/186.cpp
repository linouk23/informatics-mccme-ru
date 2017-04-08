#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int num_of_rows, num_of_cols, n;
    vector<vector<int> > g, plus_g, start_g;
    vector<int> prev;
    const int INF = (int)1e9;
public:
    void read() {
        cin >> num_of_rows >> num_of_cols;
        n = num_of_rows + num_of_cols + 2;
        g.resize(n, vector<int> (n, 0));
        plus_g.resize(n, vector<int> (n, 0));
        start_g.resize(n, vector<int> (n, 0));
        
        int source = 0;
        int sink = n - 1;
        int capacity;
        for (int row = 1; row <= num_of_rows; ++row) {
            cin >> capacity;
            g[source][row] = capacity;
        }
        
        for (int column = 1 + num_of_rows; column <= num_of_rows + num_of_cols; ++column) {
            cin >> capacity;
            g[column][sink] = capacity;
        }
        
        for (int row = 1; row <= num_of_rows; ++row) {
            for (int column = 1 + num_of_rows; column <= num_of_rows + num_of_cols; ++column) {
                cin >> capacity;
                if (capacity == -1) {
                    capacity = INF;
                    g[row][column] = capacity;
                } else {
                    plus_g[row][column] = capacity;
                    g[source][row] -= capacity;
                    g[column][sink] -= capacity;
                }
            }
        }
        
        start_g = g;
    }
    
    bool bfs(int source, int sink) {
        prev.assign(n, -1);
        queue<int> q;
        q.push(source);
        vector<bool> visited(n, false);
        visited[source] = true;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for (int neighbour = 0; neighbour < n; ++neighbour) {
                if (!visited[neighbour] && g[cur][neighbour] > 0) {
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
    
    void print_answer() {
        for (int row = 1; row <= num_of_rows; ++row) {
            for (int column = num_of_rows + 1; column <= num_of_rows + num_of_cols; ++column) {
                cout << start_g[row][column] - g[row][column] + plus_g[row][column] << " ";
            }
            cout << endl;
        }
    }
    
    void solve() {
        int source = 0;
        int sink = n - 1;
        
        for (int row = 1; row <= num_of_rows; ++row) {
            if (g[source][row] < 0) {
                cout << -1;
                return;
            }
        }
        
        for (int column = 1 + num_of_rows; column <= num_of_rows + num_of_cols; ++column) {
            if (g[column][sink] < 0) {
                cout << -1;
                return;
            }
        }
        
        int max_flow = 0;
        while(bfs(source, sink)) {
            vector<int> path = get_path(sink);
            int path_flow = get_min_flow(path);
            max_flow += path_flow;
            update_matrix(path, path_flow);
        }
        
        print_answer();
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
