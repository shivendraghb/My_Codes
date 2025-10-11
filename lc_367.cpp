#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    long long l = 1, h = n, mid;
    int f = 0;
    while(l <= h) {
        mid = l + (h - l) / 2;
        if(mid * mid == n) {
            f = 1;
            cout << "true" << '\n';
            return;
        }
        else if(n < mid * mid)
            h = mid - 1;
        else if(n > mid * mid)
            l = mid + 1;
    }

    if(!f) {cout << "false" << '\n'; return;}
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}