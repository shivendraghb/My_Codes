#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> res(n, 1);
    set<int> s;

    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) {
        if(v[i] == 0)
            s.insert(i);
        else {
            res[i] = -1;
            if(mp.count(v[i])) {
                auto it = s.lower_bound(mp[v[i]]);
                if(it == s.end()) {
                    cout << "nothing" << '\n';
                    return;
                }
                res[*it] = v[i];
                s.erase(it);
            }
            mp[v[i]] = i;
        }
    }

    for(auto i : res)
        cout << i << " ";
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