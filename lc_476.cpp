#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int num;
    cin >> num;

    if (num == 0) { cout << 1 << '\n'; return; }
    int m = 1;
    while (m < num) {
        m = (m << 1) | 1;
    }

    cout << "Solution 1: " << (num ^ m) << '\n';

    int bits = log2(num) + 1;
    int m2 = (1 << bits) - 1;

    cout << "Solution 2: " << (num ^ m2) << '\n';
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