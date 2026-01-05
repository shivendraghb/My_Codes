#include<bits/stdc++.h>
using namespace std;

// #define int long long

void solve() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> g(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    int ans = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (g[i][j] < 0)
                ans++;

    cout << "-------O(m*n)Brute-Force-------\n" << ans << '\n';

    //Start at bottom left, O(m + n)
    ans = 0;
    int i = m - 1, j = 0;

    while (i >= 0 && j < n) {
        if (g[i][j] <= 0) {
            ans += n - j;
            i--;    //move up
        } else {
            j++;
        }          //move right
    }

    cout << "-------O(m + n)Optimized-Version-------\n" << ans << '\n';
    
    //Binary-Search
    ans = 0;
    for (int i = 0; i < m; i++) {
        int l = 0, r = n - 1, pos = n;

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (g[i][mid] < 0) {
                pos = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        ans += n - pos;
    }

    cout << "-------O(m log n)Binary-Version-------\n" << ans << '\n';
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