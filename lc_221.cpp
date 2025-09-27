#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> v(m, vector<int>(n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> v[i][j];

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int max_side = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(v[i][j] == 1) {
                dp[i + 1][j + 1] = min({dp[i][j], dp[i + 1][j], dp[i][j + 1]}) + 1;
                max_side = max(max_side, dp[i + 1][j + 1]);
            }
        }
    }

    cout << max_side * max_side << '\n';
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
