#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    int total = 0, week = 1;
    for (int day = 1; day <= n; ++day) {
        total += week + (day - 1) % 7;
        if (day % 7 == 0) ++week;
    }
    cout << total << '\n';
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
