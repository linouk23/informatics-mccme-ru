#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int n;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<int> colors;
public:
    void read() {
        cin >> n;
        int weight;
        for (int start = 0; start < n; ++start) {
            for (int finish = 0; finish < n; ++finish) {
                cin >> weight;
                if (start == finish) { continue; }
                pq.push(make_tuple(weight, start, finish));
            }
        }
        colors.resize(n);
        for (int vertex = 0; vertex < n; ++vertex) {
            cin >> colors[vertex];
        }

    }
    
    void solve() {
        while(!pq.empty()) {
            int start, finish;
            tie(std::ignore, start, finish) = pq.top(); pq.pop();
            if (colors[start] == 0 && colors[finish] == 1) {
                cout << start + 1 << " " << finish + 1;
                return;
            }
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
