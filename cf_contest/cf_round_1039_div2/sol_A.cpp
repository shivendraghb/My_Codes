#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    // DP with bitmask approach
    vector<int> dp(1 << n, LLONG_MAX);
    dp[0] = 0;

    for(int mask = 0; mask < (1 << n); mask++) {
        if(dp[mask] == LLONG_MAX) continue;

        int destroyed = __builtin_popcount(mask);

        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) continue;

            int new_mask = mask | (1 << i);

            // Check if a[i] * (2^destroyed) > c
            int cost = 0;
            if(destroyed >= 60) {
                // If destroyed >= 60, multiplier is huge, definitely > c
                cost = 1;
            } else {
                int multiplier = 1LL << destroyed;
                // Check if a[i] > c/multiplier to avoid overflow
                if(a[i] > c / multiplier) {
                    cost = 1;
                }
            }

            dp[new_mask] = min(dp[new_mask], dp[mask] + cost);
        }
    }

    cout << dp[(1 << n) - 1] << '\n';
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
