#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m;
    vector<vector<int>> matrix;
public:
    void read() {
        cin >> n >> m;
        matrix.resize(n, vector<int> (n, 0));
        int a, b;
        for (int edge = 0; edge < m; ++edge) {
            cin >> a >> b;
            --a; --b;
            matrix[a][b] = 1;
        }
    }
    
    void solve() {
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                cout << matrix[row][column] << " ";
            }
            cout << endl;
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
