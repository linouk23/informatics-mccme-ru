#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
    vector<vector<int>> matrix;
    vector<int> colors;
public:
    void read() {
        cin >> n;
        matrix.resize(n, vector<int> (n, 0));
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                cin >> matrix[row][column];
            }
        }

        colors.resize(n);
        for (int vertex = 0; vertex < n; ++vertex) {
            cin >> colors[vertex];
        }
    }

    int find_num() {
        int answer = 0;
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                if (matrix[row][column] && colors[row] != colors[column]) {
                    ++answer;
                }
            }
        }
        return answer / 2;
    }
};

int main() {
    ios::sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);

    Solution solution;
    solution.read();
    cout << solution.find_num();

    return 0;
}
