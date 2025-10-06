#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> v[i][j];

    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    auto dfs = [&](int r, int c, int mid, vector<vector<bool>>& seen, auto& dfs_ref) -> bool {
        if (r == n - 1 && c == n - 1) return true;
        seen[r][c] = true;

        for(auto [dr, dc] : dir) {
            int nr = r + dr, nc = c + dc;
            if(nr >= 0 && nr < n && nc >= 0 && nc < n && !seen[nr][nc]) {
                if(v[nr][nc] <= mid) {
                    if(dfs_ref(nr, nc, mid, seen, dfs_ref)) return true;
                }
            }
        }
        return false;
    };

    auto possible = [&](int mid) {
        if (v[0][0] > mid) return false;
        vector<vector<bool>> seen(n, vector<bool>(n, false));
        return dfs(0, 0, mid, seen, dfs);
    };

    int lo = v[0][0], hi = 0;
    for(auto& row : v)
        for(int val : row)
            hi = max(hi, val);

    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if(possible(mid)) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << '\n';
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