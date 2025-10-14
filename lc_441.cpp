#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    int l = 0, h = n;
    while(l <= h) {
        int mid = l + (h - l) / 2;
        if(n >= (mid * (mid + 1) / 2)) l = mid + 1;
        else h = mid - 1;
    }

    cout << l - 1 << '\n';
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