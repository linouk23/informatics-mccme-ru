#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
    vector<vector<int>> matrix;
public:
    void read() {
        cin >> n;
        matrix.resize(n, vector<int> (n, 0));
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                cin >> matrix[row][column];
            }
        }
    }
    
    void solve() {
        int answer = 0;
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                if (matrix[row][column]) {
                    ++answer;
                }
            }
        }
        cout << answer;
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
