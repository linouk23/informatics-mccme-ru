#include <bits/stdc++.h>

using namespace std;

const int MAXN = 123456;

class Solution {
private:
    int n;
    vector<int> g[MAXN];
public:
    void read() {
        cin >> n;
        string str;
        getline(cin, str);
        for (int line = 0; line < n; ++line) {
            getline(cin, str);
            stringstream ss(str);
            string item;
            while(getline(ss, item, ' ')) {
                int vertex = stoi(item) - 1;
                g[vertex].emplace_back(line);
            }
        }
    }
    
    void solve() {
        cout << n << endl;
        for (int vertex = 0; vertex < n; ++vertex) {
            for (int neighbour : g[vertex]) {
                cout << neighbour + 1 << " ";
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
