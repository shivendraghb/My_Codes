#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    int n;
    cin >> s >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int m = s.size();
    int t = 0;

    for(int i = 1; i < n; i++) {
        if(s[i] == s[i - 1]) {
            t += min(v[i], v[i - 1]);
            v[i] = max(v[i], v[i - 1]);
        }
    }

    cout << t << '\n';
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