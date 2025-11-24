#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    vector<long long> dp(3, LLONG_MIN/4);
    dp[0] = 0;
    for (int x : v) {
        vector<long long> ndp = dp;
        int m = (int)(x % 3);
        for (int r = 0; r < 3; ++r) {
            ndp[(r + m) % 3] = max(ndp[(r + m) % 3], dp[r] + x);
        }
        dp.swap(ndp);
    }
    cout << dp[0] << '\n';
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