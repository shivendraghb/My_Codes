#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    cin >> s;

    int i = 0, n = s.size();
    while(i < n && s[i] == 'a')
        i++;
    if(i == n)
        s[n - 1] = 'z';
    while(i < n && s[i] != 'a')
        --s[i++];

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