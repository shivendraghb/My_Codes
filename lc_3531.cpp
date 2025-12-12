#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> b(m, vector<int>(2));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < 2; j++)
            cin >> b[i][j];

    unordered_map<int, pair<int, int>> r, c;
    // r[x] = {min_y, max_y}
    // c[y] = {min_x, max_x}

    for(auto &p : b) {
        int x = p[0], y = p[1];

        if(!r.count(x)) r[x] = {y, y};
        else {
            r[x].first = min(r[x].first, y);
            r[x].second = max(r[x].second, y);
        }
        
        if(!c.count(y)) c[y] = {x, x};
        else {
            c[y].first = min(c[y].first, x);
            c[y].second = max(c[y].second, x);
        }
    }

    int ans = 0;
    for(auto &p : b) {
        int x = p[0], y = p[1];
        if (r[x].first < y && y < r[x].second &&
            c[y].first < x && x < c[y].second)
            ans++;
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