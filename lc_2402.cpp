#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mt(m, vector<int>(2));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 2; j++)
            cin >> mt[i][j];

    sort(mt.begin(), mt.end());

    priority_queue<int, vector<int>, greater<int>> free;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;

    for (int i = 0; i < n; i++) free.push(i);

    vector<long long> cnt(n);

    for (auto &m : mt) {
        long long s = m[0], e = m[1];

        while (!busy.empty() && busy.top().first <= s) {
            free.push(busy.top().second);
            busy.pop();
        }

        if (!free.empty()) {
            int r = free.top(); free.pop();
            busy.push({e, r});
            cnt[r]++;
        } else {
            auto [t, r] = busy.top(); busy.pop();
            busy.push({t + (e - s), r});
            cnt[r]++;
        }
    }

    int ans = 0;
    for (int i = 1; i < n; i++)
        if (cnt[i] > cnt[ans]) ans = i;

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