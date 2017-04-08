#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int n, m;
    vector<vector<long long> > g;
    vector<int> prev;
    const long long INF = (long long)1e18;
public:
    void read() {
        cin >> n >> m;
        g.resize(n, vector<long long> (n, 0));
        int start, finish, weight;
        for (int edge = 0; edge < m; ++edge) {
            cin >> start >> finish >> weight;
            --start; --finish;
            g[start][finish] += weight;
        }
        prev.resize(n);
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
    
    long long get_min_flow(vector<int> &path) {
        long long path_flow = INF;
        for (int index = 0; index < (int)path.size() - 1; ++index) {
            int from = path[index];
            int to = path[index + 1];
            path_flow = min(path_flow, g[from][to]);
        }
        return path_flow;
    }
    
    void update_matrix(vector<int> &path, long long path_flow) {
        for (int index = 0; index < (int)path.size() - 1; ++index) {
            int from = path[index];
            int to = path[index + 1];
            g[from][to] -= path_flow;
            g[to][from] += path_flow;
        }
    }
    
    void solve() {
        long long max_flow = 0;
        int source = 0;
        int sink = n - 1;
        while(bfs(source, sink)) {
            
            vector<int> path;
            int t_sink = sink;
            while(t_sink != -1) {
                path.emplace_back(t_sink);
                t_sink = prev[sink];
            }
            
            
            long long path_flow = INF;
            for (int index = (int)path.size() - 1; index >= 1; --index) {
                int from = path[index];
                int to = path[index - 1];
                path_flow = min(path_flow, g[from][to]);
            }
            
            for (int index = (int)path.size() - 1; index >= 1; --index) {
                int from = path[index];
                int to = path[index - 1];
                g[from][to] -= path_flow;
                g[to][from] += path_flow;
            }

            max_flow += path_flow;
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
