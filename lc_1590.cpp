#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, p;
    cin >> n >> p;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    // long total = 0;
    // for(int x : v) total += x;

    // long target = total % p;
    // if (target == 0) { cout << 0 << '\n'; }

    // unordered_map<int, int> mp;
    // mp[0] = -1;

    // long prefix = 0;
    // int res = n;

    // for(int i = 0; i < n; i++) {
    //     prefix = (prefix + v[i]) % p;
    //     int need = (prefix - target + p) % p;

    //     if (mp.count(need))
    //         res = min(res, i - mp[need]);

    //     mp[(int)prefix]  = i;
    // }

    // cout << (res == n ? -1 : res) << '\n';

    long s = 0; for(int x : v) s += x;
    int r = s % p; if (!r) { cout << 0 << '\n'; return; }

    unordered_map<int, int> m; m[0] = -1;
    long pre = 0; int ans = n;

    for(int i = 0; i < n; i++) {
        pre = (pre + v[i]) % p;
        int w = (pre - r + p) % p;
        if (m.count(w)) ans = min(ans, i - m[w]);
        m[pre] = i;
    }

    cout << (ans == n ? -1 : ans) << '\n';
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