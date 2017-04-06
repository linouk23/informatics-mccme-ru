#include "bits/stdc++.h"

using namespace std;

struct Edge {
    int weight, start, finish;
    
    Edge(int weight, int start, int finish) :
    weight(weight), start(start),
    finish(finish) {}
    
    bool operator <(const Edge& op) const {
        return weight < op.weight;
    }
};

class Solution {
private:
    int n, m, k, start, finish;
    vector<Edge> edges;
    const int INF = (int)1e9;
public:
    void read() {
        cin >> n >> m >> k >> start >> finish;
        --start;
        --finish;
        int from, to, weight;
        for (int edge = 0; edge < m; ++edge) {
            cin >> from >> to >> weight;
            --from; --to;
            edges.emplace_back(weight, from, to);
        }
    }
    
    void solve() {
        vector<vector<int> > distance(n, vector<int> (k + 1, INF));
        distance[start][0] = 0;
        for (int iteration = 1; iteration <= k; ++iteration) {
            for (int vertex = 0; vertex < n; ++vertex) {
                distance[vertex][iteration] = distance[vertex][iteration - 1];
            }
            
            for (const auto & edge : edges) {
                if (distance[edge.finish][iteration] > distance[edge.start][iteration - 1] + edge.weight) {
                    distance[edge.finish][iteration] = distance[edge.start][iteration - 1] + edge.weight;
                }
            }
        }
        cout << ((distance[finish][k] == INF) ? -1 : distance[finish][k]);
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
