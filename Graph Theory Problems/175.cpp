#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;

class Solution {
private:
    vector<int> g[MAXN];
    int n, m;
public:
    void read() {
        cin >> n >> m;
        int a, b;
        for (int edge = 0; edge < m; ++edge) {
            cin >> a >> b;
            --a; --b;
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
    }
    void print_degrees() {
        for (int vertex = 0; vertex < n; ++vertex) {
            cout << g[vertex].size() << " ";
        }
    }
};

int main() {
    ios::sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);

    Solution solution;
    solution.read();
    solution.print_degrees();

    return 0;
}
