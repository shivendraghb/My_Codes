#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    cin >> s;

    long t = 0, end = 0, mod = 1000000007;

    for(int i = 0; i < s.size(); i++) {
        int k = s[i] - '0';
        end = (10 * end + (i + 1) * k) % mod;
        t = (t + end) % mod;
    }

    cout << t << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;

    // while(t--) {
    //     solve();
    // }
    solve();

    return 0;
}