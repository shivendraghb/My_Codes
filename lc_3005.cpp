#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    unordered_map<int, int> mp;
    for(int i : v) mp[i]++;

    int max_freq = 0;
    for(auto [_, f] : mp)
        max_freq = max(max_freq, f);

    int cnt = 0;
    for(auto [_, f] : mp)
        if(f == max_freq)
            cnt++;

    cout << cnt * max_freq << '\n';
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
