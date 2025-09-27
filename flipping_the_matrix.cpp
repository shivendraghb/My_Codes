#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(2 * n, vector<int>(2 * n));
    for(int i = 0; i < 2 * n; i++)
        for(int j = 0; j < 2 * n; j++)
            cin >> v[i][j];

    int s = v.size();
    int sum = 0;

    for(int i = 0; i < s / 2; i++) {
        for(int j = 0; j < s / 2; j++) {
            sum += max({v[i][j], v[s - i - 1][j], v[i][s - j - 1],
            v[s - i - 1][s - j - 1]});
        }
    }

    cout << sum << '\n';
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
