#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    vector<int> arr(m * n);
    for (int i = 0; i < m * n; i++)
        cin >> arr[i];

    unordered_map<int, pair<int, int>> pos;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            pos[mat[i][j]] = {i, j};

    vector<int> rc(m, 0);
    vector<int> cc(n, 0);

    for (int i = 0; i < m * n; i++) {
        auto [r, c] = pos[arr[i]];

        rc[r]++;
        cc[c]++;

        if (rc[r] == n || cc[c] == m) { cout << i << '\n'; return; }
    }

    cout << -1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.toe(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}