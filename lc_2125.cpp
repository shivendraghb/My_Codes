#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<string> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int ans = 0, prev = 0;

    for(auto& i : v) {
        int device = count(i.begin(), i.end(), '1');
        if(device > 0) {
            ans += device * prev;
            prev = device;
        }
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