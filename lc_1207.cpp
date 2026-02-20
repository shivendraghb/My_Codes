#include<bits/stdc++.h>
using namespace std;

// #define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[v[i]]++;

    unordered_set<int> s;
    for (auto i : mp)
        s.insert(i.second);
        
    if (mp.size() == s.size()) {
        cout << "true" << '\n';
        return;
    } else {
        cout << "false" << '\n';
        return;
    }

    sort(v.begin(), v.end());
    int c = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1])
            c++;
        else {
            s.insert(c);
            c = 1;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}