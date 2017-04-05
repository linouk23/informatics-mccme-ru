#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int n, m, start, finish;
    vector<int> prices;
    vector<vector<int> > g;
    const int INF = (int)1e9;
public:
    void read() {
        cin >> n;
        start = 0;
        finish = n - 1;
        prices.resize(n);
        for (int vertex = 0; vertex < n; ++vertex) {
            cin >> prices[vertex];
        }
        
        g.resize(n, vector<int> (n, 0));
        cin >> m;
        int from, to;
        for (int edge = 0; edge < m; ++edge) {
            cin >> from >> to;
            --from; --to;
            g[from][to] = 1;
            g[to][from] = 1;
        }
    }
    
    void solve() {
        vector<vector<int> > visited(n, vector<int> (2, 0));
        vector<vector<int> > distance(n, vector<int> (2, INF));
        
        int cisterns_left = 0;
        distance[start][cisterns_left] = 0;
        for (int iteration = 0; iteration < 2 * n; ++iteration) {
            int min_dist_prev_vertex = 0, cisterns_left_in_prev_vertex = 0;
            bool has_found = false;
            for (int vertex = 0; vertex < n; ++vertex) {
                for (cisterns_left = 0; cisterns_left <= 1; ++cisterns_left) {
                    if (visited[vertex][cisterns_left]) { continue; }
                    if (!has_found || distance[vertex][cisterns_left] <
                        distance[min_dist_prev_vertex][cisterns_left_in_prev_vertex]) {
                        min_dist_prev_vertex = vertex;
                        cisterns_left_in_prev_vertex = cisterns_left;
                        has_found = true;
                    }
                }
            }
            
            visited[min_dist_prev_vertex][cisterns_left_in_prev_vertex] = true;
            for (int vertex = 0; vertex < n; ++vertex) {
                if (!g[min_dist_prev_vertex][vertex]) { continue; }
                for (cisterns_left = 0; cisterns_left <= 1; ++cisterns_left) {
                    int cisterns_bought_in_prev_vertex = cisterns_left -
                    cisterns_left_in_prev_vertex + 1;
                    int price = cisterns_bought_in_prev_vertex * prices[min_dist_prev_vertex];
                    if (distance[vertex][cisterns_left] >
                        distance[min_dist_prev_vertex][cisterns_left_in_prev_vertex] + price) {
                        distance[vertex][cisterns_left] =
                        distance[min_dist_prev_vertex][cisterns_left_in_prev_vertex] + price;
                    }
                    
                }
            }
        }
        int answer = min(distance[finish][0], distance[finish][1]);
        cout << ((answer == INF) ? -1 : answer);
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    freopen("input.txt", "r", stdin);
    
    Solution solution;
    solution.read();
    solution.solve();
    
    return 0;
}
