#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int MAXN = 123;
    const int INF = (int)1e9;
    vector<vector<pair<int, int>>> g;
    vector<char> visited;
    vector<int> distance;
    vector<int> prev;
    int n, start, finish;
public:
    void read() {
        g.resize(MAXN);
        cin >> n >> start >>  finish;
        int weight;
        --start; --finish;
        for (int vertex = 0; vertex < n; ++vertex) {
            for (int neighbour = 0; neighbour < n; ++neighbour) {
                cin >> weight;
                if (weight <= 0) { continue; }
                g[vertex].emplace_back(neighbour, weight);
            }
        }
    }


    void solve() {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        prev.resize(n, -1);
        visited.resize(n, 0);
        distance.resize(n, INF);
        distance[start] = 0;
        min_heap.push({distance[start], start});
        while (!min_heap.empty()) {
            int min_dist_vertex = min_heap.top().second; min_heap.pop();
            if (visited[min_dist_vertex]) { continue; }
            visited[min_dist_vertex] = 1;
            for (const auto & edge : g[min_dist_vertex]) {
                int neighbour = edge.first, weight = edge.second;
                if (distance[neighbour] >= distance[min_dist_vertex] + weight) {
                    distance[neighbour] = distance[min_dist_vertex] + weight;
                    prev[neighbour] = min_dist_vertex;
                    min_heap.push({distance[neighbour], neighbour});
                }
            }
        }
        if (!visited[finish]) {
            cout << -1;
        } else {
            vector<int> path;
            while(finish != -1) {
                path.emplace_back(finish);
                finish = prev[finish];
            }
            reverse(path.begin(), path.end());
            for (int vertex : path) {
                cout << vertex + 1 << " ";
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
