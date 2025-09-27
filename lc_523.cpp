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

    mp[0] = -1;

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += v[i];

        if(mp.count(sum % k)) {
            if(i - mp[sum % k] >= 2) {
                cout << "true" << '\n';
                return;
            }
        }
        else
            mp[sum % k] = i;
    }

    cout << "false" << '\n';
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
