#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> e(n);
    for(int i = 0; i < n; i++)
        cin >> e[i];

    vector<int> dp(n);

    int r = INT_MIN;

    for(int i = n - 1; i >= 0; i--) {
        dp[i] = e[i] + ((i + k < n) ? dp[i + k] : 0);
        r = max(r, dp[i]);
    }

    cout << r << '\n';
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