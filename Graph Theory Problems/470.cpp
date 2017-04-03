#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m;
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
        for (int row = 0; row < n; ++row) {
            int degree = 0;
            for (int column = 0; column < n; ++column) {
                degree += matrix[row][column];
            }
            cout << degree << endl;
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
