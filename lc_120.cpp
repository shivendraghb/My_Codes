#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> v(n);
    for(int i = 0; i < n; i++) {
        v[i].resize(i + 1);
        for(int j = 0; j <= i; j++)
            cin >> v[i][j];
    }

    vector<int> dp = v.back();

    for(int i = n - 2; i >= 0; i--)
        for(int j = 0; j <= i; j++)
            dp[j] = v[i][j] + min(dp[j], dp[j + 1]);

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
