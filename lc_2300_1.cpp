#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int m, n, k;
    cin >> m >> n >> k;

    vector<int> s(m);
    vector<int> p(n);

    for(int i = 0; i < m; i++)
        cin >> s[i];
    
    for(int i = 0; i < n; i++)
        cin >> p[i];

    int freq[100001] = {0}, pMax = 0;
    for(int i : p) {
        freq[i]++ṁ;
        pMax = max(pMax, i);
    }

    partial_sum(freq, freq + pMax + 1, freq);

    vector<int> r(m, 0);

    for(int i = 0; i < m; i++) {
        const int spell = s[i];
        const long long j = (k + spell - 1) / spell;
        if(j <= pMax)
            r[i] = n - (j >= 1 ? freq[j - 1] : 0);
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
