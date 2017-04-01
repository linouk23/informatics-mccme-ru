#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e9;

struct Cell {
    int row, column, weight;

    Cell() {}
    Cell(int row, int column) :
         row(row), column(column) {}

    bool operator <(const Cell& op) const {
        if (row != op.row)
            return row < op.row;
        return column < op.column;
    }

    bool operator ==(const Cell& op) const {
        return (row == op.row) && (column == op.column);
    }

    bool operator !=(const Cell& op) const {
        return (row != op.row) || (column != op.column);
    }
};

class Solution {
private:
    Cell start, finish;
    vector<string> matrix;
    int n, m;

    vector<int> distance;
    vector<int> prev;
    vector<bool> used;
    pair<int, int> start_pos;
    pair<int, int> finish_pos;
    vector<int> dx = {-1, 1,  0, 0};
    vector<int> dy = { 0, 0, -1, 1};

    map <char, int> prices = {
        {'.', 1},
        {'W', 2},
    };
    const int num_of_edges = 4;
public:
    void read() {
        cin >> n >> m >> start_pos.first >> start_pos.second >> 
               finish_pos.first >> finish_pos.second;
        --start_pos.first; --start_pos.second;
        --finish_pos.first; --finish_pos.second;

        matrix.resize(n);
        distance.resize(n * m);
        prev.resize(n * m);
        used.resize(n * m, false);
        getline(cin, matrix[0]);
        for (int row = 0; row < n; ++row) {
            getline(cin, matrix[row]);
        }
    }

    int ind(const Cell& cell) {
        return cell.row * m + cell.column;
    }

    int ind(int row, int column) {
        return row * m + column;
    }

    bool is_in_board(int row, int column) {
        return (row >= 0) && (row < n) &&
               (column >= 0) && (column < m);
    }

    void solve() {
        Cell start(start_pos.first, start_pos.second);
        Cell finish(finish_pos.first, finish_pos.second);

        vector<int> distance(n * m, INF);
        distance[ind(start)] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, ind(start)});
        prev[ind(start)] = -1;
        while(!pq.empty()) {
            auto min_dist_pair = pq.top(); pq.pop();
            int row = min_dist_pair.second / m;
            int column = min_dist_pair.second % m;
            int cur_vertex = ind(row, column);
            if (used[cur_vertex]) { continue; }
            used[cur_vertex] = true;
            for (int edge = 0; edge < num_of_edges; ++edge) {
                int neighbour_row = row + dy[edge];
                int neighbour_column = column + dx[edge];
                if (!is_in_board(neighbour_row, neighbour_column) ||
                    matrix[neighbour_row][neighbour_column] == '#') {
                    continue;
                }
                int neighbour = ind(neighbour_row, neighbour_column);
                int weight = prices[matrix[neighbour_row][neighbour_column]];
                
                if (distance[neighbour] > distance[cur_vertex] + weight) {
                    distance[neighbour] = distance[cur_vertex] + weight;
                    prev[neighbour] = cur_vertex;
                    pq.push({distance[neighbour], neighbour});
                }
            }
        }
        int last_vertex = finish.row * m + finish.column;

        if (distance[last_vertex] == INF) {
            cout << -1;
            return;
        }
        cout << distance[last_vertex] << endl;
        vector<int> path;
        while(last_vertex != -1) {
            path.emplace_back(last_vertex);
            last_vertex = prev[last_vertex];
        }
        reverse(path.begin(), path.end());
        for (int index = 1; index < (int)path.size(); ++index) {
            int prev_row = path[index - 1] / m;
            int prev_col = path[index - 1] % m;
            int cur_row  = path[index] / m;
            int cur_col  = path[index] % m;
            if (prev_row > cur_row) {
                cout << "N";
            } else if (prev_row < cur_row) {
                cout << "S";
            } else if (prev_col < cur_col) {
                cout << "E";
            } else {
                cout << "W";
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
