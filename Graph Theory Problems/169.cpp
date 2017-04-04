#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m, start, finish;
    vector<int> weights;
    vector<vector<pair<int, int>>> g;
    const int INF = (int)1e9;
public:
    void read() {
        cin >> n;
        start = 0;
        finish = n - 1;
        weights.resize(n);
        for (int vertex = 0; vertex < n; ++vertex) {
            cin >> weights[vertex];
        }
        
        g.resize(n);
        cin >> m;
        int from, to;
        for (int edge = 0; edge < m; ++edge) {
            cin >> from >> to;
            --from; --to;
            g[from].emplace_back(to, weights[from]);
            g[to].emplace_back(from, weights[to]);
        }
    }

    void solve() {
        vector<char> visited(n, 0);
        vector<int> distance(n, INF);
        vector<int> prev(n, -1);
        distance[start] = 0;
        prev[start] = -1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        min_heap.push({distance[start], start});
        while(!min_heap.empty()) {
            int min_dist_vertex = min_heap.top().second; min_heap.pop();
            if (visited[min_dist_vertex]) { continue; }
            visited[min_dist_vertex] = 1;
            for (const auto & edge : g[min_dist_vertex]) {
                int neighbour = edge.first, weight = edge.second;
                if (distance[neighbour] > distance[min_dist_vertex] + weight) {
                    distance[neighbour] = distance[min_dist_vertex] + weight;
                    prev[neighbour] = min_dist_vertex;
                    min_heap.push({distance[neighbour], neighbour});
                }
            }
        }
        if (visited[finish]) {
            vector<int> path;
            while(finish != -1) {
                path.emplace_back(finish);
                finish = prev[finish];
            }
            reverse(path.begin(), path.end());
            int answer = 0;
            for (int index = 0; index < (int)path.size() - 1; ++index) {
                int vertex = path[index];
                answer += weights[vertex];
            }
            cout << answer;
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
