#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int a, b, k;
    cin >> a >> b >> k;

    int g = __gcd(a, b);

    int dx = a / g;
    int dy = b / g;

    if(dx <= k && dy <= k)
        cout << 1 << '\n';
    else
        cout << 2 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
