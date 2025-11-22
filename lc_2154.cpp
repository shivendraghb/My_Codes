#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, org;
    cin >> n >> org;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    unordered_set<int> s(v.begin(), v.end());
    
    while(s.count(org))
        org *= 2;

    cout << org << '\n';
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