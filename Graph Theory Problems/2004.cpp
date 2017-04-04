#include <bits/stdc++.h>

using namespace std;

struct Vertex {
    string num;
    int rem;
    Vertex(string num, int rem) : num(num), rem(rem) {}
};

const int MAXDIVISOR = 123456;

class Solution {
private:
    string num;
    int n, divisor;
    vector<int> digits;
    unordered_set<int> visited;
    unordered_map<int, int> dist;
    vector<int> g[MAXDIVISOR];
public:
    void read() {
        cin >> num >> divisor;
        cin >> n;
        digits.resize(n);
        for (int index = 0; index < n; ++index) {
            cin >> digits[index];
        }
        sort(digits.begin(), digits.end());
    }

    void create_graph() {
        for (int rem = 0; rem < divisor; ++rem) {
            for (int digit : digits) {
                int new_rem = (10 * rem + digit) % divisor;
                g[new_rem].emplace_back(rem);
            }
        }
    }

    int get_start_rem() {
        int rem = 0;
        for (int index = 0; index < (int)num.size(); ++index) {
            int digit = num[index] - 48;
            rem = (10 * rem + digit) % divisor;
        }
        return rem;
    }

    int get_new_rem(int old_rem, int added_digit) {
        return (10 * old_rem + added_digit) % divisor;
    }

    void solve() {
        create_graph();
        int finish = get_start_rem();
        int start = 0;
        dist[0] = 0;
        visited.insert(0);
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int cur_rem = q.front(); q.pop();
            for (int new_rem : g[cur_rem]) {
                if (!visited.count(new_rem)) {
                    q.push(new_rem);
                    visited.insert(new_rem);
                    dist[new_rem] = dist[cur_rem] + 1;
                }
            }
        }
        if (!dist.count(finish)) {
            cout << -1;
        } else {
            cout << num;
            while(dist[finish] != 0) {
                for (int digit : digits) {
                    int new_rem = get_new_rem(finish, digit);
                    if (dist[new_rem] == dist[finish] - 1) {
                        cout << digit;
                        finish = new_rem;
                        break;
                    }
                }
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
