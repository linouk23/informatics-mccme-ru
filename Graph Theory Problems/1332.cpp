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
                dist[row][column] = weight;
            }
        }
    }
    
    void solve() {
        for (int intermediate = 0; intermediate < n; ++intermediate) {
            for (int from = 0; from < n; ++from) {
                for (int to = 0; to < n; ++to) {
                    dist[from][to] = max(dist[from][to],
                                         min(dist[from][intermediate], dist[intermediate][to]));
                }
            }
        }
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                cout << dist[row][column] << " ";
            }
            cout << endl;
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
