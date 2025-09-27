#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        vector<int> cnt(n+1, 0);
        for (int x : a) cnt[x]++;

        vector<int> dp(n+1, 0);
        int ans = 0;
        for (int x = 1; x <= n; x++) {
            if (cnt[x] == 0) continue;
            dp[x] = cnt[x];
            if (x <= n) dp[x] = (cnt[x] / x) * x;
            ans = max(ans, dp[x]);
        }

        cout << ans << "\n";
    }
}
