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
        dist.resize(n, vector<int> (n, 0));
        
        int from, to, weight;
        for (int edge = 0; edge < m; ++edge) {
            cin >> from >> to >> weight;
            --from; --to;
            dist[from][to] = weight;
            dist[to][from] = weight;
        }
    }
    
    void print_matrix() {
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                cout << dist[row][column] << "   ";
            }
            cout << endl;
        }
    }
    
    void solve() {
        for (int intermediate = 0; intermediate < n; ++intermediate) {
            for (int from = 0; from < n; ++from) {
                for (int to = 0; to < n; ++to) {
                    if (min(dist[from][intermediate], dist[intermediate][to]) == 0) { continue; }
                    if (dist[from][to] == 0 ||
                        dist[from][to] > dist[from][intermediate] + dist[intermediate][to]) {
                        dist[from][to] = dist[from][intermediate] + dist[intermediate][to];
                    }
                }
            }
        }
        
        if (m == 0) {
            cout << 0;
            return;
        }
        //        print_matrix();
        pair<int, int> answer = {0, 1};
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                if (row == column) { continue; }
                if (dist[row][column] > dist[answer.first][answer.second]) {
                    answer = {row, column};
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
