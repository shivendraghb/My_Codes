#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    cin >> s;

    string ss = s + s;

    string alt1 = "", alt2 = "";
    
    for (int i = 0; i < 2 * s.size(); i++) {
        alt1 += (i % 2 ? '1' : '0');
        alt2 += (i % 2 ? '0' : '1');
    }

    int diff1 = 0, diff2 = 0;
    int ans = LLONG_MAX;

    int l = 0;

    for (int r = 0; r < 2 * s.size(); r++) {
        if (ss[r] != alt1[r]) diff1++;
        if (ss[r] != alt2[r]) diff2++;

        if (r - l + 1 > s.size()) {
            if (ss[l] != alt1[l]) diff1--;
            if (ss[l] != alt2[l]) diff2--;
            l++;
        }

        if (r - l + 1 == s.size())
            ans = min(ans, min(diff1, diff2));
    }

    cout << ans << '\n';
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
