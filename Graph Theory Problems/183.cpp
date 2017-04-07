#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int n;
    vector<int> arr;
public:
    void read() {
        cin >> n;
        arr.resize(n);
        for (int index = 0; index < n; ++index) {
            cin >> arr[index];
        }
    }
    
    void solve() {
        int q, w;
        cin >> q >> w;
        --q; --w;
        int color_1 = arr[q];
        int color_2 = arr[w];
        for (int index = 0; index < n; ++index) {
            if (arr[index] == color_1) {
                arr[index] = color_2;
            }
        }
        for (int index = 0; index < n; ++index) {
            cout << arr[index] << " ";
        }
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
