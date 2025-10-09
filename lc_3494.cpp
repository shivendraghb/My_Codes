#include<bits/stdc++.h>
using namespace std;

// #define int long long

void solve() {
    int m, n;
    cin >> m >> n;

    vector<int> s(m);
    for(int i = 0; i < m; i++)
        cin >> s[i];

    vector<int> mana(n);
    for(int i = 0; i < n; i++)
        cin >> mana[i];

    vector<long long> done(m + 1, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            done[j + 1] = max(done[j + 1], done[j]) + 1LL * mana[i] * s[j];

        for(int j = m - 1; j > 0; j--)
            done[j] = done[j + 1] - 1LL * mana[i] * s[j];
    }

    cout << done[m] << '\n';
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