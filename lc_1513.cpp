#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    cin >> s;

    int cnt = 0, t = 0, mod = 1e9 + 7;
    for (char c : s) {
        if (c == '1') cnt++;
        else cnt = 0;
        t = (t + cnt) % mod;
    }

    cout << t << '\n';
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