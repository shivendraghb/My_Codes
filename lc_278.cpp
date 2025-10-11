#include<bits/stdc++.h>
using namespace std;

#define int long long

bool isBadVersion(int mid) {
    if(mid % 2 == 0)
        return true;
    else
        return false;
}

void solve() {
    int n;
    cin >> n;

    long long l = 1, h = n, mid;
    while(l <= h) {
        mid = l + (h - l) / 2;
        if(isBadVersion(mid))
            h = mid - 1;
        else
            l = mid + 1;
    }

    cout << l << '\n';
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