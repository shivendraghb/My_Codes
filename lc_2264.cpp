#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    cin >> s;

    string ans = "";

    for(int i = 0; i + 2 < s.size(); i++) {
        if(s[i] == s[i + 1] && s[i] == s[i + 2])
            ans = max(ans, s.substr(i, 3));
    }

    cout << ans << '\n';
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
