#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    unordered_map<int, int> mp;

    int r = 0, sum = 0;
    mp[0] = 1;
    for(int i : v) {

        sum += i;

        int mod = sum % k;

        if(mod < 0)
            mod += k;

        if(mp.count(mod)) {
            r += mp[mod];
            mp[mod]++;
        }
        else
            mp[mod] = 1;

    }

    cout << r << '\n';
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
