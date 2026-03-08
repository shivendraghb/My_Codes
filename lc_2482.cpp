#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> onesRow(m, 0);
    vector<int> onesCol(n, 0);

    // Count 1s in rows and columns
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) {
                onesRow[i]++;
                onesCol[j]++;
            }
        }
    }

    // Output the diff matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int val = 2 * onesRow[i] + 2 * onesCol[j] - m - n;
            cout << val << " ";
        }
        cout << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}