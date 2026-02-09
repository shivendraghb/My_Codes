#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> p(n, vector<int>(2));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 2; j++)
            cin >> p[i][j];

    int ans = 0;

    for(int i = 1; i < n; i++) {
        int dx = abs(p[i][0] - p[i - 1][0]);
        int dy = abs(p[i][1] - p[i - 1][1]);
        ans += max(dx, dy);
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