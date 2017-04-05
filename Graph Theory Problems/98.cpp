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
                if (row == column) {
                    dist[row][column] = 0;
                } else if (weight == 1) {
                    dist[row][column] = -123;
                } else {
                    dist[row][column] = INF;
                }
            }
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
                    dist[from][to] = min(dist[from][to],
                                         dist[from][intermediate] + dist[intermediate][to]);
                }
                for (int vertex = 0; vertex < n; ++vertex) {
                    if (dist[vertex][vertex] < 0) {
                        cout << 1;
                        return;
                    }
                }
            }
        }
        cout << 0;
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
