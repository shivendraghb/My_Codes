#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = 3; i <= n; i++) {
        for(int j = 0; j + i - 1 < n; j++) {
            int k = j + i - 1;
            dp[j][k] = LLONG_MAX;
            for(int l = j + 1; l < k; l++) {
                dp[j][k] = min(dp[j][k], dp[j][l] + dp[l][k] + v[j] * v[l] * v[k]);
            }
        }
    }

    cout << dp[0][n - 1] << '\n';
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