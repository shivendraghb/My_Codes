#include<bits/stdc++.h>
using namespace std;

// #define int long long

void solve() {
    int n, c;
    cin >> n >> c;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int m = c, cnt = 0, i = 0;
    while(m > 0) {
        if(v[i++] < m) {
            m -= v[i];
            cnt++;
        }
    }

    cout << cnt << '\n';
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