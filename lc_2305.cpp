#include<bits/stdc++.h>
using namespace std;

// #define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> cookies(n);
    for(int i = 0; i < n; i++)
        cin >> cookies[i];

    int dp[7][255] = {};

    auto mask_sum = [&](const vector<int>& cookies, int mask) {
        int s = 0;
        for(int i = 0; i < cookies.size(); i++)
            s += (mask & (1 << i)) ? cookies[i] : 0;
        return s;
    };

    auto distributeCoookies = [&](const vector<int>& cookies, int k, int i = 0, int mask = 0) {
        int l = (1 << cookies.size()) - 1;
        if(i == k - 1) {
            int ans = mask_sum(cookies, l - mask);
            cout << ans << '\n';
            return;
        }
        if(dp[i][mask] == 0) {
            dp[i][mask] == INT_MAX;
            for(int mask_i = 1; mask_i < l; mask_i++)
                if((mask_i & mask) == 0 && __builtin_popcount(l - mask_i - mask) >= k - i - 1)
                    dp[i][mask] = min(dp[i][mask], max(distributeCoookies(cookies, k, i + 1, mask + mask_i), mask_sum(cookies, mask_i)));
        }

        return dp[i][mask];
    };

    int res = distributeCoookies(cookies, k, i = 0, mask = 0);

    cout << res << '\n';
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