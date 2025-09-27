#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int r, c;
    cin >> r >> c;
    r--;
    int row_start = (r / 2) * 10;
    if (r % 2 == 0) {
        cout << row_start + (2 * (c - 1)) << '\n';
    } else {
        cout << row_start + (2 * (c - 1)) + 1 << '\n';
    }
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
