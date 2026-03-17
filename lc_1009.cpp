#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    int m = 1;
    while (m < n) {
        m = (m << 1) | 1;
    }

    cout << "Solution 1: " << (n ^ m) << '\n';

    int bits = log2(n) + 1;
    int m2 = (1 << bits) - 1;

    cout << "Solution 2: " << (n ^ m2) << '\n';
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