#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int m, c;
    cin >> m >> c;

    m -= c;
    if(m < 0) {
        cout << -1 << '\n';
        return;
    }
    if(m / 7 == c && m % 7 == 0) {
        cout << c << '\n';
        return;
    }
    if(m / 7 == c - 1 && m % 7 == 3) {
        cout << c - 2 << '\n';
        return; 
    }

    cout << min(c - 1, m / 7);
    return;
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