#include<bits/stdc++.h>
using namespace std;

// #define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> f(k);
    f[0] = 1;
    // cout << f[3] << '\n';
    int s = 0, ans = 0, x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        s = (s + x) % k;
        if (s < 0) s += k;
        cout << s << " ";
        //int t = (s - 1 +k) % k;
        //ans += f[t];
        ans += f[s];
        cout << ans << " ";
        ++f[s];
        cout << f[s] << '\n';
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