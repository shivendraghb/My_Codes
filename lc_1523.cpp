#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int l, h;
    cin >> l >> h;

    cout << (h + 1) / 2 - l / 2 << '\n';
}

int32_t main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
