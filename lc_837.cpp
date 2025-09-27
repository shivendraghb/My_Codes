#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k, maxpts;
    cin >> n >> k >> maxpts;

    if(k == 0 || n >= k + maxpts - 1) {
        cout << fixed << setprecision(6) << 1.0 << '\n';
        return;
    }

    vector<double> dp(n + 1, 0.0);
    dp[0] = 1.0;

    double windowsum = 1.0;
    double result = 0.0;

    for(int i = 1; i <= n; i++) {
        dp[i] = windowsum / maxpts;

        if(i < k)
            windowsum += dp[i];
        else
            result += dp[i];

        if(i - maxpts >= 0)
            windowsum -= dp[i - maxpts];

    }
    cout << fixed << setprecision(6) << result << '\n';
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
