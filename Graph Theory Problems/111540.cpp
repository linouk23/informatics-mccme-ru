#include <bits/stdc++.h>

using namespace std;

const int MAXN = 123456;

class Solution {
private:
    vector<int> g[MAXN];
    int n, m;
    vector<bool> used;
    vector<int> component;
    vector<vector<int>> components;
public:
    void read() {
        cin >> n >> m;
        used.resize(n, false);
        int a, b;
        for (int edge = 0; edge < m; ++edge) {
            cin >> a >> b;
            --a; --b;
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
    }

    void dfs(int vertex) {
        used[vertex] = true;
        component.emplace_back(vertex + 1);
        for (const auto & neighbor : g[vertex]) {
            if (!used[neighbor]) {
                dfs(neighbor);
            }
        }
    }

    void print() {
        cout << (int)components.size() << endl;
        for (const auto & component : components) {
            cout << (int)component.size() << endl;
            for (int vertex : component) {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }

    void find_num() {
        int answer = 0;
        for (int vertex = 0; vertex < n; ++vertex) {
            if (!used[vertex]) {
                dfs(vertex);
                ++answer;
                components.emplace_back(component);
                component.clear();
            }
        }
        print();
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
