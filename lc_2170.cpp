#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &x : nums) cin >> x;

    unordered_map<int,int> even, odd;

    for (int i = 0; i < n; i++) {
        if (i % 2) odd[nums[i]]++;
        else even[nums[i]]++;
    }

    vector<pair<int,int>> e, o;

    for (auto &x : even)
        e.push_back({x.second, x.first});

    for (auto &x : odd)
        o.push_back({x.second, x.first});

    sort(e.rbegin(), e.rend());
    sort(o.rbegin(), o.rend());

    int e1 = e.size() ? e[0].first : 0;
    int e2 = e.size() > 1 ? e[1].first : 0;

    int o1 = o.size() ? o[0].first : 0;
    int o2 = o.size() > 1 ? o[1].first : 0;

    int ev = e.size() ? e[0].second : -1;
    int ov = o.size() ? o[0].second : -1;

    int ans;

    if (ev != ov)
        ans = n - (e1 + o1);
    else
        ans = min(n - (e1 + o2), n - (e2 + o1));

    cout << ans << endl;
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) solve();
}