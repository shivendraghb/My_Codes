#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, target;
    cin >> n >> target;

    vector<int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++) {
        if(mp.count(target - a[i]))
            cout << mp[target - a[i]] << " " << i << '\n';
        mp[a[i]] = i;
    }

    return;
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
