#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> keep(n), del(n);

    keep[0] = a[0];
    del[0] = -1e9;

    int ans = a[0];

    for(int i = 1; i < n; i++) {
        keep[i] = max(keep[i - 1] + a[i], a[i]);
        del[i] = max(del[i - 1] + a[i], keep[i - 1]);

        ans = max({ans, keep[i], del[i]});
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
