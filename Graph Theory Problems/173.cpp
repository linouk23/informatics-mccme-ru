#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int n;
    vector<vector<double> > dist;
    vector<vector<int> > answer;
    const double INF = 1e90;
public:
    void read() {
        cin >> n;
        
        dist.resize(n, vector<double> (n, 0));
        answer.resize(n, vector<int> (n));
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                cin >> dist[row][column];
                if (dist[row][column] == 0 && row != column) {
                    dist[row][column] = INF;
                }
                
                if (dist[row][column] > 0 && row == column) {
                    dist[row][column] = 0;
                }
            }
        }
    }
    
    void print_matrix() {
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                cout << answer[row][column] << " ";
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
                    if (dist[from][to] >= INF / 2.0) {
                        dist[from][to] = INF;
                    }
                }
            }
        }
        for (int from = 0; from < n; ++from) {
            for (int to = 0; to < n; ++to) {
                if (dist[from][to] == INF) {
                    answer[from][to] = 0;
                } else {
                    answer[from][to] = 1;
                    for (int intermediate = 0; intermediate < n; ++intermediate) {
                        if (dist[from][intermediate] < INF &&
                            dist[intermediate][to] < INF &&
                            dist[intermediate][intermediate] < 0) {
                            answer[from][to] = 2;
                        }
                    }
                }
            }
        }
        
        print_matrix();
    }
};

int main() {
    ios::sync_with_stdio(false);
    
        // freopen("input.txt", "r", stdin);
    
    Solution solution;
    solution.read();
    solution.solve();
    
    return 0;
}
