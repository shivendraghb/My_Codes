#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    // unordered_map<int, int> mp;
    // vector<int> res;

    // for(int i = 0; i < n; i++) {
    //     mp[v[i]]++;

    //     if(mp[v[i]] == 2) res.push_back(v[i]);
    // }

    // for(int i : res)
    //     cout << i << " ";

    // cout << '\n';

    unordered_map<int, int> mp;
    vector<bool> seen(n, false);
    vector<int> res;

    for(int i = 0; i < n; i++) {
        if(seen[v[i]]) res.push_back(v[i]);
        else seen[v[i]] = true;
    }

    for(int i : res) cout << i << " ";
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