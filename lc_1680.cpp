#include<bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    
    long long ans = 0;
    int length = 0;
    
    for (int i = 1; i <= n; i++) {
        if ((i & (i - 1)) == 0)
            length++;

        ans = ((ans << length) | i) % MOD;
    }

    cout << (int)ans << '\n';
    // cout << sizeof(long) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}