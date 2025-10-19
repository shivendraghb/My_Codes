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

    for(int i = n - 2; i >= 0; i--)
        v[i] = (v[i] + v[i + 1]) % 26;

    for(int i = 0; i < n; i++)
        s[i] = 'a' + (s[i] - 'a' + v[i]) % 26;

    cout << s << '\n';
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