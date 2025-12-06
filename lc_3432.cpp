#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int ts = accumulate(v.begin(), v.end(), 0);
    int s = 0, cnt = 0;

    if (ts % 2 != 0) { cout << 0 << '\n'; return; }

    for(int i = 0; i < n - 1; i++) {
        s += v[i];
        if ((ts - s) % 2 == 0) cnt++;
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