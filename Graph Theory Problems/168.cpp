#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, start, finish;
    vector<vector<pair<int, int>>> g;
    const int INF = (int)1e9;
public:
    void read() {
        cin >> n >> start >> finish;
        --start; --finish;
        
        g.resize(n);
        int weight;
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                cin >> weight;
                if (weight == -1) { continue; }
                g[row].emplace_back(column, weight);
            }
        }
    }

    void solve() {
        vector<char> visited(n, 0);
        vector<int> distance(n, INF);
        distance[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        min_heap.push({distance[start], start});
        while(!min_heap.empty()) {
            int min_dist_vertex = min_heap.top().second; min_heap.pop();
            if (visited[min_dist_vertex]) { continue; }
            visited[min_dist_vertex] = true;

            for (const auto & edge : g[min_dist_vertex]) {
                int neighbour = edge.first, weight = edge.second;
                if (distance[neighbour] > distance[min_dist_vertex] + weight) {
                    distance[neighbour] = distance[min_dist_vertex] + weight;
                    min_heap.push({distance[neighbour], neighbour});
                }
            }
        }
        if (visited[finish]) {
            cout << distance[finish];
        } else {
            cout << -1;
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
