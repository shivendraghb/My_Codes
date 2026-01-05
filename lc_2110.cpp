#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    for(int i = 0; i < n; i++)
        cin >> p[i];

    // int ans = 0;
    // for(int i = 0; i < n; i++) {
    //     ans++;
    //     for(int j = i; j + 1 < n; j++) {
    //         if (p[j] - p[j + 1] == 1)
    //             ans++;
    //         else
    //             break;
    //     }
    // }

    // cout << ans << '\n';

    // int ans = 1, len = 1;
    // for (int i = 1; i < n; i++) {
    //     if (p[i - 1] - p[i] == 1)
    //         len++;
    //     else
    //         len = 1;
    //     ans += len;
    // }

    // cout << ans << '\n';

    // vector<int> dp(n);
    // dp[0] = 1;
    // int ans = 1;
    // for(int i = 1; i < n; i++) {
    //     if (p[i - 1] - p[i] == 1)
    //         dp[i] = dp[i - 1] + 1;
    //     else
    //         dp[i] = 1;
    //     ans += dp[i];
    // }

    // cout << ans << '\n';

    int ans = 1, dp = 1;
    for (int i = 1; i < n; i++) {
        dp = (p[i - 1] - p[i] == 1) ? dp + 1 : 1;
        ans += dp;
    }

    cout << ans << '\n';
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