#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int cnt = 0, l = 0, r = 0;
    for(int i : v) r += i;

    for(int i = 0; i < n; i++) {
        l += v[i];
        r -= v[i];
        if(v[i] != 0) continue;
        if(l == r) cnt += 2;
        if(abs(l - r) == 1) cnt++;
    }

    cout << cnt << '\n';
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