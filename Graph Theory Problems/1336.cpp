#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int n, m, start, finish;
    vector<vector<double> > dist;
    const double INF = 1e9;
public:
    void read() {
        cin >> n >> m >> start >> finish;
        --start; --finish;
        dist.resize(n, vector<double> (n, 0));
        
        for (int vertex = 0; vertex < n; ++vertex) {
            dist[vertex][vertex] = 1;
        }
        
        int from, to;
        double weight;
        for (int edge = 0; edge < m; ++edge) {
            cin >> from >> to >> weight;
            --from; --to;
            dist[from][to] = 1 - weight / 100.0;
            dist[to][from] = 1 - weight / 100.0;
        }
    }
    
    void print_matrix() {
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                cout << dist[row][column] << " ";
            }
            cout << endl;
        }
    }
    
    void solve() {
        for (int intermediate = 0; intermediate < n; ++intermediate) {
            for (int from = 0; from < n; ++from) {
                for (int to = 0; to < n; ++to) {
                    dist[from][to] = max(dist[from][to],
                                         (dist[from][intermediate] * dist[intermediate][to]));
                }
            }
        }
        printf("%lf", 1.0 - dist[start][finish]);
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
