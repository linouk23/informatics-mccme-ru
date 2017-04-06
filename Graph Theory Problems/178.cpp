#include "bits/stdc++.h"

using namespace std;

struct Edge {
    int weight;
    int start;
    int finish;
    
    Edge(int weight, int start, int finish) :
    weight(weight), start(start),
    finish(finish) {}
    
    bool operator <(const Edge& op) const {
        return weight < op.weight;
    }
};

class Solution {
private:
    int n, m;
    vector<Edge> edges;
    const int INF = (int)1e9;
public:
    void read() {
        cin >> n >> m;
        int start, finish, weight;
        for (int edge = 0; edge < m; ++edge) {
            cin >> start >> finish >> weight;
            --start; --finish;
            edges.emplace_back(weight, start, finish);
        }
    }
    
    void solve() {
        vector<int> distance(n, INF);
        distance[0] = 0;
        for (int iteration = 0; iteration < n - 1; ++iteration) {
            for (int index = 0; index < m; ++index) {
                Edge edge = edges[index];
                if (distance[edge.start] >= INF / 2) { continue; }
                distance[edge.finish] = min(distance[edge.finish],
                                            distance[edge.start] + edge.weight);
            }
        }
        for (int vertex = 0; vertex < n; ++vertex) {
            cout << ((distance[vertex] >= INF / 2) ? 30000 : distance[vertex]) << " ";
        }
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
