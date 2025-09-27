#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> a(2*n);
    for(int i=0;i<2*n;i++) cin >> a[i];

    vector<int> vals(n);
    for(int i=0;i<n;i++) {
        vals[i] = a[n+i] - a[i];
    }

    sort(vals.begin(), vals.end());
    vector<int> pref(n+1,0);
    for(int i=0;i<n;i++) {
        pref[i+1] = pref[i] + vals[i];
    }

    // output answers for k = 1..n
    for(int k=1;k<=n;k++) {
        cout << pref[n] - pref[n-k] << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}