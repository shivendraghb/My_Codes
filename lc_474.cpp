#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int s, m, n;
    cin >> s >> m >> n;

    vector<string> v(s);
    for(int i = 0; i < s; i++)
        cin >> v[i];

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (auto &i : v) {
        int z = count(i.begin(), i.end(), '0');
        int o = i.size() - z;

        for (int i = m; i >= z; i--) {
            for (int j = n; j >= o; j--) {
                dp[i][j] = max(dp[i][j], 1 + dp[i - z][j - o]);
            }
        }
    }

    cout << dp[m][n] << '\n';
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