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
        cin >> n;
        int start, finish, weight;
        for (start = 0; start < n; ++start) {
            for (finish = 0; finish < n; ++finish) {
                cin >> weight;
                if (weight == 100000) {
                    continue;
                }
                edges.emplace_back(weight, start, finish);
            }
        }
    }
    
    void solve() {
        vector<int> distance(n, INF);
        vector<int> prev(n, -1);
        distance[0] = 0;
        m = (int)edges.size();
        bool has_neg_cycle = false;
        int last_updated_vertex = -1;
        for (int iteration = 1; iteration <= n; ++iteration) {
            for (int index = 0; index < m; ++index) {
                Edge edge = edges[index];
                if (distance[edge.finish] > distance[edge.start] + edge.weight) {
                    distance[edge.finish] = distance[edge.start] + edge.weight;
                    prev[edge.finish] = edge.start;
                    last_updated_vertex = edge.finish;
                    if (iteration == n) {
                        has_neg_cycle = true;
                    }
                };
            }
        }
        if (has_neg_cycle) {
            cout << "YES" << endl;
            for (int iteration = 1; iteration <= n; ++iteration) {
                last_updated_vertex = prev[last_updated_vertex];
            }
            int begin = last_updated_vertex;
            vector<int> path;
            while(true) {
                path.emplace_back(last_updated_vertex);
                last_updated_vertex = prev[last_updated_vertex];
                if (last_updated_vertex == begin && path.size() > 1) { break; }
            }
            path.emplace_back(last_updated_vertex);
            reverse(path.begin(), path.end());
            cout << (int)path.size() << endl;
            for (int vertex : path) {
                cout << vertex + 1 << " ";
            }
        } else {
            cout << "NO";
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
