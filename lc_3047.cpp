#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> bl(n, vector<int>(2)), tr(n, vector<int>(2));
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> bl[i][j];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> tr[i][j];

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long left = max(bl[i][0], bl[j][0]);
            long long right = min(tr[i][0], tr[j][0]);
            long long bottom = max(bl[i][1], bl[j][1]);
            long long top = min(tr[i][1], tr[j][1]);

            if (left < right && bottom < top) {
                long long side = min(right - left, top - bottom);
                ans = max(ans, side * side);
            }
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