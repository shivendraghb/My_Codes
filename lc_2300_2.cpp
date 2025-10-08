#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int m, n, k;
    cin >> m >> n >> k;

    vector<int> s(m);
    for(int i = 0; i < m; i++)
        cin >> s[i];
    
    vector<int> p(n);
    for(int i = 0; i < n; i++)
        cin >> p[i];

    sort(p.begin(), p.end());
    
    vector<int> r(m, 0);

    const int maxPotion = p[n - 1];

    for(int i = 0; i < m; i++) {
        int spell = s[i];
        long long j = (k + spell - 1) / spell;
        if(j <= maxPotion)
            r[i] = n - (lower_bound(p.begin(), p.end(), j) - p.begin());
    }

    for(int i : r)
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