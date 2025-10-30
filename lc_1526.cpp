#include<bits/stdc++.h>
using namespace std;

// #define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int res = v[0];
    for(int i = 1; i < n; i++)
        res += max(v[i] - v[i - 1], 0);

    cout << res << '\n';
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