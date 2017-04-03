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
        vector<int> in_degree(n), out_degree(n);
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                if (matrix[row][column]) {
                    ++in_degree[column];
                    ++out_degree[row];
                }
            }
        }
        int count = 0;
        for (int vertex = 0; vertex < n; ++vertex) {
            if (!in_degree[vertex]) {
                ++count;
            }
        }
        cout << count << endl;
        for (int vertex = 0; vertex < n; ++vertex) {
            if (!in_degree[vertex]) {
                cout << vertex + 1 << endl;
            }
        }

        count = 0;
        for (int vertex = 0; vertex < n; ++vertex) {
            if (!out_degree[vertex]) {
                ++count;
            }
        }
        cout << count << endl;
        for (int vertex = 0; vertex < n; ++vertex) {
            if (!out_degree[vertex]) {
                cout << vertex + 1 << endl;
            }
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
