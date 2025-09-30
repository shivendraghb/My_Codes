#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> g(n);
    vector<int> c(m);

    for(int i = 0; i < n; i++)
        cin >> g[i];
    
    for(int i = 0; i < m; i++)
        cin >> c[i];

    int curr, req, start;
    curr = req = start = 0;

    for(int i = 0; i < n; i++) {
        curr += g[i] - c[i];

        if(curr < 0) {
            req += curr;
            start = i + 1;
            curr = 0;
        }
    }

    cout << ((curr + req >= 0) ? start : -1) << '\n';
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