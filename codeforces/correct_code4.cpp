#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<array<int, 3>> a(n);

    for(auto &[l, r, h] : a)
        cin >> l >> r >> h;

    sort(a.begin(), a.end());
    int ans = k;

    for(auto [l, r, h] : a)
        if(ans >= l) ans = max(ans, h);

    cout << ans << '\n';
}

int32_t main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
