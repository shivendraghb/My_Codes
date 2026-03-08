#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    vector<int> rc(m, 0);
    vector<int> cc(n, 0);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(mat[i][j] == 1) {
                rc[i]++;
                cc[j]++;
            }
        }
    }

    int special = 0;

    for (int i = 0; i < m; i++) {
        if(rc[i] == 1) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && cc[j] == 1)
                    special++;
            }
        }
    }

    cout << special << '\n';
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
