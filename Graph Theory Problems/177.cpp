#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

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

    void find_num() {
        int best_distance = INF;
        vector<int> result;
        for (int v1 = 0; v1 < n; ++v1) {
            for (int v2 = 0; v2 < n; ++v2) {
                for (int v3 = 0; v3 < n; ++v3) {
                    if (v1 == v2 || v2 == v3 || v1 == v3) { continue; }
                    if (matrix[v1][v2] + matrix[v2][v3] + matrix[v3][v1] < best_distance) {
                        best_distance = matrix[v1][v2] + matrix[v2][v3] + matrix[v3][v1];
                        result = {v1, v2, v3};
                    }
                }
            }
        }
        for (int vertex : result) {
            cout << vertex + 1 << " ";
        }
    }
};

int main() {
    ios::sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);

    Solution solution;
    solution.read();
    solution.find_num();

    return 0;
}
