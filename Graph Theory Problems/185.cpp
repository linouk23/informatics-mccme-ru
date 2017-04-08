#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int n, m;
    vector<tuple<int, int, int> > edges;
    vector<int> parents, size;
public:
    void read() {
        cin >> n >> m;
        int start, finish, weight;
        for (int edge = 0; edge < m; ++edge) {
            cin >> start >> finish >> weight;
            --start; --finish;
            edges.emplace_back(make_tuple(weight, start, finish));
        }
    }
    
    void disjoint_set_union_init() {
        parents.resize(n);
        size.resize(n);
        for (int vertex = 0; vertex < n; ++vertex) {
            parents[vertex] = vertex;
            size[vertex] = 1;
        }
    }
    
    int disjoint_set_union_find(int vertex) {
        if (vertex == parents[vertex]) {
            return vertex;
        }
        return parents[vertex] = disjoint_set_union_find(parents[vertex]);
    }
    
    void disjoin_set_union_merge(int v1, int v2) {
        int r1 = disjoint_set_union_find(v1);
        int r2 = disjoint_set_union_find(v2);
        if (r1 != r2) {
            if (size[r1] < size[r2]) { swap(r1, r2); }
            parents[r2] = r1;
            size[r2] += size[r1];
        }
    }
    
    void solve() {
        sort(edges.begin(), edges.end());
        disjoint_set_union_init();
        int answer = 0;
        for (const auto & edge : edges) {
            int weight, start, finish;
            tie(weight, start, finish) = edge;
            if (disjoint_set_union_find(start) != disjoint_set_union_find(finish)) {
                answer += weight;
                disjoin_set_union_merge(start, finish);
            }
        }
        cout << answer;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
//    freopen("input.txt", "r", stdin);
    
    Solution solution;
    solution.read();
    solution.solve();
    
    return 0;
}