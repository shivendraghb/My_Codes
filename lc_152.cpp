#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int max_prod = v[0], min_prod = v[0], ans = v[0];
    for(int i = 1; i < n; i++) {
        if(v[i] < 0) swap(max_prod, min_prod);
        max_prod = max(v[i], max_prod * v[i]);
        min_prod = min(v[i], min_prod * v[i]);
        ans = max(ans, max_prod);
    }
    cout << ans << '\n';
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
