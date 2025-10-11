#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    unordered_map<int, long long> mp;
    for(int p : v) mp[p]++;

    vector<int> keys;
    
    for(auto& [k, _] : mp) keys.push_back(k);
    sort(keys.begin(), keys.end());

    int m = keys.size();

    vector<long long> dp(m);

    dp[0] = mp[keys[0]] * keys[0];

    for(int i = 1; i < m; i++) {
        long long take = mp[keys[i]] * keys[i];
        int prev = upper_bound(keys.begin(), keys.begin() + i, keys[i] - 3) - keys.begin() - 1;
        if(prev >= 0) take += dp[prev];
        dp[i] = max(dp[i - 1], take);
    }

    cout << dp[m - 1] << " ";

    cout << '\n';
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