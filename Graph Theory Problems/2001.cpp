#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    string start, finish;
    const int num_of_ops = 4;
    unordered_map<string, int> distance;
    unordered_map<string, string> prev;
    unordered_set<string> visited;
public:
    void read() {
        cin >> start >> finish;
    }

    string plus(string num) {
        if (num[0] == '9') { return num; }

        num[0] += 1;
        return num;
    }

    string minus(string num) {
        if (num[3] == '1') { return num; }

        num[3] -= 1;
        return num;
    }

    string left_shift(string num) {
        return num.substr(1,3) + num.substr(0, 1);
    }

    string right_shift(string num) {
        return num.substr(3,1) + num.substr(0, 3);
    }

    void solve() {
        queue<string> q;
        visited.insert(start);
        distance[start] = 0;
        q.push(start);
        prev[start] = "";
        while(!q.empty()) {
            string num = q.front(); q.pop();
            if (num == finish) {
                break;
            }

            string new_num;

            for (int operation = 0; operation < num_of_ops; ++operation) {
                switch (operation) {
                    case 0: new_num = plus(num);
                            break;
                    case 1: new_num = minus(num);
                            break;
                    case 2: new_num = right_shift(num);
                            break;
                    case 3: new_num = left_shift(num);
                            break;
                }

                if (!visited.count(new_num)) {
                    visited.insert(new_num);
                    q.push(new_num);
                    prev[new_num] = num;
                    distance[new_num] = distance[num] + 1;
                }
            }

        }
        vector<string> path;
        while(finish != "") {
            path.emplace_back(finish);
            finish = prev[finish];
        }
        reverse(path.begin(), path.end());
        for (const auto & str : path) {
            cout << str << endl;
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
