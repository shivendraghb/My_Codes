#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    vector<long long> minP(k, LLONG_MAX);
    minP[0] = 0;
    long long ps = 0, ans = LLONG_MIN;
    for(int i = 1; i <= n; i++) {
        ps += v[i - 1];
        int r = i % k;
        if (minP[r] != LLONG_MAX) ans = max(ans, ps - minP[r]);
        minP[r] = min(minP[r], ps);
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