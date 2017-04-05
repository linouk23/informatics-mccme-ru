#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int n, start, finish;
    vector<vector<int> > dist;
    const int INF = (int)1e9;
public:
    void read() {
        cin >> n;
        dist.resize(n, vector<int> (n, 0));
        int weight;
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                cin >> weight;
                if (weight == -1) {
                    dist[row][column] = INF;
                } else {
                    dist[row][column] = weight;
                }
            }
        }
    }
    
    void solve() {
        for (int intermediate = 0; intermediate < n; ++intermediate) {
            for (int from = 0; from < n; ++from) {
                for (int to = 0; to < n; ++to) {
                    dist[from][to] = min(dist[from][to],
                                         dist[from][intermediate] + dist[intermediate][to]);
                }
                
                for (int vertex = 0; vertex < n; ++vertex) {
                    if (dist[vertex][vertex] < 0) {
                        cout << -1;
                        return;
                    }
                }
            }
        }
        
        pair<int, int> answer = {0, 1};
        for (int start = 0; start < n; ++start) {
            for (int finish = 0; finish < n; ++finish) {
                if (start == finish) { continue; }
                if (dist[start][finish] < dist[answer.first][answer.second]) {
                    answer = {start, finish};
                }
            }
        }
        cout << dist[answer.first][answer.second];
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
