#include <bits/stdc++.h>

using namespace std;

// const int INF = 1e9;

class Solution {
private:
    vector<vector<int>> matrix;
    int n;
    int answer = 0;
    int start_vertex;
    vector<bool> used;
public:
    void read() {
        cin >> n >> start_vertex;
        matrix.resize(n, vector<int> (n, 0));
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                cin >> matrix[row][column];
            }
        }
    }

    void dfs(int vertex) {
        used[vertex] = true;
        ++answer;
        for (int index = 0; index < n; ++index) {
            if (matrix[vertex][index] && !used[index]) {
                dfs(index);
            }
        }
    }

    int find_num() {
        used.resize(n, false);
        --start_vertex;
        dfs(start_vertex);
        return answer;
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
