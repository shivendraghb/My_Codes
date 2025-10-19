#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    int k;
    cin >> s >> k;

    for(int i = 0; i < s.size() && k > 0; i++) {
        int dist_a = min(s[i] - 'a', 'z' - s[i] + 1);
        s[i] = dist_a <= k ? 'a' : s[i] - k;
        k -= dist_a;
    }

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