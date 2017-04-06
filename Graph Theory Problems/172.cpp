#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int n;
    vector<vector<int> > dist;
    const int INF = (int)1e9;
public:
    void read() {
        cin >> n;
        
        dist.resize(n, vector<int> (n, 0));
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                cin >> dist[row][column];
                if (dist[row][column] == -1) {
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
            }
        }
        int max_value = -1;
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                if (dist[row][column] != INF && dist[row][column] > max_value) {
                    max_value = dist[row][column];
                }
            }
        }
        cout << max_value;
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
