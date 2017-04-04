#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int MAXN = 61234;
    const int INF = 2009000999;
    vector<vector<pair<int, int>>> g;
    int n, m, start;
public:
    void read() {
        g.clear();
        g.resize(MAXN);

        cin >> n >> m;
        int a, b, weight;
        for (int edge = 0; edge < m; ++edge) {
            cin >> a >> b >> weight;
            g[a].emplace_back(b, weight);
            g[b].emplace_back(a, weight);
        }
        cin >> start;
    }

    void solve() {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        vector<char> visited(n, 0);
        vector<int> distance(n, INF);
        distance[start] = 0;
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
        for (int vertex = 0; vertex < n; ++vertex) {
            cout << distance[vertex] << " ";
        }
        cout << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);

    Solution solution;
    int num_of_tests;
    cin >> num_of_tests;
    for (int test = 0; test < num_of_tests; ++test) {
        solution.read();
        solution.solve();
    }


    return 0;
}
