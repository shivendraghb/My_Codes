#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int k;
    cin >> k;

    if (k % 2 == 0 || k % 5 == 0) {
        cout << -1 << '\n';
        return;
    }
    int rem = 0;
    int ans = -1;
    for (int i = 1; i <= k; ++i) {
        rem = (rem * 10 + 1) % k;
        if (rem == 0) { ans = i; break; }
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