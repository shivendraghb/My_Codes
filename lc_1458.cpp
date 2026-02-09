#include<bits/stdc++.h>
using namespace std;

// #define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> n1(n);
    for(int i = 0; i < n; i++)
        cin >> n1[i];
    
    vector<int> n2(m);
    for(int i = 0; i < m; i++)
        cin >> n2[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1e9));

    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            int take = n1[i] * n2[j];

            take += max(0, dp[i + 1][j + 1]);

            int skip1 = dp[i + 1][j];
            int skip2 = dp[i][j + 1];

            dp[i][j] = max({take, skip1, skip2});
        }
    }

    cout << dp[0][0] << '\n';
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