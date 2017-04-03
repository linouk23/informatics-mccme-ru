#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
    vector<vector<int>> matrix;
public:
    void read() {
        cin >> n;
        matrix.resize(n, vector<int> (n));
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                cin >> matrix[row][column];
            }
        }
    }
    
    void solve() {
        for (int v1 = 0; v1 < n; ++v1) {
            for (int v2 = 0; v2 < n; ++v2) {
                for (int v3 = 0; v3 < n; ++v3) {
                    if (v1 != v2 && v2 != v3 && v1 != v3) {
                        if (matrix[v1][v2] && matrix[v2][v3] &&
                            matrix[v1][v3] == 0) {
                            cout << "NO";
                            return;
                        }
                    }
                }
            }
        }
        cout << "YES";
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
