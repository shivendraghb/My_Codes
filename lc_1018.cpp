#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int rem = 0;
    for (int i = 0; i < n; ++i) {
        rem = (rem * 2 + v[i]) % 5;
        cout << (rem == 0 ? 1 : 0) << (i + 1 == n ? '\n' : ' ');
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