#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int MAXN = 523;
    const int INF = (int)1e9;
    vector<vector<pair<int, int>>> g;
    map<pair<int, pair<int, int>>, int> limit;
    int n, m, start, finish;
public:
    void read() {
        g.resize(MAXN);

        cin >> n >> m;
        start = 0;
        finish = n - 1;
        int a, b, weight, weight_limit;
        for (int edge = 0; edge < m; ++edge) {
            cin >> a >> b >> weight >> weight_limit;
            weight_limit -= 3 * (int)1e6;
            --a; --b;
            g[a].emplace_back(b, weight);
            g[b].emplace_back(a, weight);
            limit[{a, {b, weight}}] = limit[{b, {a, weight}}] = weight_limit / 100;
        }
    }

    bool sp(int cups) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        vector<char> visited(n, 0);
        vector<int> distance(n, INF);
        distance[start] = 0;
        min_heap.push({distance[start], start});
        while(!min_heap.empty()) {
            int min_dist_vertex = min_heap.top().second; min_heap.pop();
            if (visited[min_dist_vertex]) { continue; }
            visited[min_dist_vertex] = 1;
            for (const auto & edge : g[min_dist_vertex]) {
                int neighbour = edge.first, weight = edge.second;
                if (distance[neighbour] > distance[min_dist_vertex] + weight &&
                    limit[{min_dist_vertex, edge}] >= cups) {
                    distance[neighbour] = distance[min_dist_vertex] + weight;
                    min_heap.push({distance[neighbour], neighbour});
                }
            }
        }
        return distance[finish] <= 1440;
    }


    void solve() {
        int L = 0, R = (int)1e7 + 1;
        while (R - L > 1) {
            int M = L + (R - L) / 2;
            if (sp(M)) {
                L = M;
            } else {
                R = M;
            }
        }
        cout << L;
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
