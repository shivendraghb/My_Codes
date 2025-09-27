#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
// gcd(a,b) = gcd(a, a-b)
// Why it’s bad:
// If a and b are close (e.g. a = n, b = n-1)
// you do ~n subtractions.
// Each subtraction of n-bit numbers costs O(n) bit-ops,
// so worst-case bit-cost O(n * value) — impractical.
// Small example: gcd(10^9, 10^9 - 1) would take
// about a billion steps
    long long  a, b;
    cin >> a >> b;

    if(a < 0) a = -a;
    if(b < 0) b = -b;
    if(a == 0) {cout << b << '\n'; return;}
    if(b == 0) {cout << a << '\n'; return;}

    while(a != b) {
        if(a > b) a -= b;
        else b -= a;
    }

    cout << a << '\n';
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
