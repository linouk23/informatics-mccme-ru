#include <bits/stdc++.h>

using namespace std;

const int MAXN = 123456;

class Solution {
private:
    int n, m;
    vector<int> g[MAXN];
    vector<int> in_degree, out_degree;
public:
    void read() {
        cin >> n >> m;
        in_degree.resize(n);
        out_degree.resize(n);

        int a, b;
        for (int edge = 0; edge < m; ++edge) {
            cin >> a >> b;
            --a; --b;
            ++out_degree[a];
            ++in_degree[b];
        }
    }
    
    void solve() {
        for (int vertex = 0; vertex < n; ++vertex) {
            cout << in_degree[vertex] << endl << out_degree[vertex] << endl;
        }
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
