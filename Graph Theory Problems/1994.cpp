#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int n;
    const int INF = (int)1e9;
public:
    void read() {
        cin >> n;
    }
    
    void solve() {
        vector<int> distance(n, INF);
        distance[0] = 0;
        bool any;
        int weight;
        for (int iteration = 1; iteration < n; ++iteration) {
            any = false;
            for (int start = 0; start < n; ++start) {
                for (int finish = start + 1; finish < n; ++finish) {
                    weight = (179 * (start + 1) + 719 * (finish + 1)) % 1000 - 500;
                    if (distance[finish] > distance[start] + weight) {
                        distance[finish] = distance[start] + weight;
                        any = true;
                    }
                }
            }
            if (!any) { break; }
        }
        cout << distance[n - 1];
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
