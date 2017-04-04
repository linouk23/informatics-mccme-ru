#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int to, dep_time, arr_time;
    Edge(int to, int dep_time, int arr_time) : 
        to(to), dep_time(dep_time), arr_time(arr_time) {}
};

class Solution {
private:
    int n, m, start, finish;
    vector<vector<Edge>> g;
    const int INF = (int)1e9;
public:
    void read() {
        cin >> n;
        cin >> start >> finish;
        --start; --finish;

        g.resize(n);
        cin >> m;
        int from, dep_time, to, arr_time;
        for (int edge = 0; edge < m; ++edge) {
            cin >> from >> dep_time >> to >> arr_time;
            --from; --to;
            g[from].emplace_back(to, dep_time, arr_time);
        }
    }

    void solve() {
        vector<char> visited(n, 0);
        vector<int> distance(n, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        distance[start] = 0;
        min_heap.push({distance[start], start});
        while(!min_heap.empty()) {
            int min_dist_vertex = min_heap.top().second; min_heap.pop();
            if (visited[min_dist_vertex]) { continue; }
            visited[min_dist_vertex] = 1;
            for (const auto & edge : g[min_dist_vertex]) {
                int neighbour = edge.to, dep_time = edge.dep_time, arr_time = edge.arr_time;
                if (distance[neighbour] > arr_time &&
                    distance[min_dist_vertex] <= dep_time) {
                    distance[neighbour] = arr_time;
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
