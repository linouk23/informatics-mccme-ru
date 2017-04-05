#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int n, m;
    vector<vector<int> > dist;
    const int INF = (int)1e9;
public:
    void read() {
        cin >> n >> m;
        dist.resize(n, vector<int> (n, INF));
        
        for (int vertex = 0; vertex < n; ++vertex) {
            dist[vertex][vertex] = 0;
        }
        
        int from, to, weight;
        for (int edge = 0; edge < m; ++edge) {
            cin >> from >> to >> weight;
            --from; --to;
            dist[from][to] = weight;
            dist[to][from] = weight;
        }
    }
    
    void solve() {
        for (int intermediate = 0; intermediate < n; ++intermediate) {
            for (int from = 0; from < n; ++from) {
                for (int to = 0; to < n; ++to) {
                    dist[from][to] = min(dist[from][to],
                                         dist[from][intermediate] + dist[intermediate][to]);
                }
            }
        }
        
        vector<int> max_dist_from(n, 0);
        for (int start = 0; start < n; ++start) {
            for (int finish = 0; finish < n; ++finish) {
                max_dist_from[start] = max(max_dist_from[start],
                                           dist[start][finish]);
            }
        }
        
        int best_ind = 0;
        for (int vertex = 0; vertex < n; ++vertex) {
            if (max_dist_from[vertex] < max_dist_from[best_ind]) {
                best_ind = vertex;
            }
        }
        cout << best_ind + 1;
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
