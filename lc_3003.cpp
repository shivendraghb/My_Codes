#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    cin >> s;

    int k;
    cin >> k;

    if(k == 26) {cout << 1 << '\n'; return;}

    int n = s.size();
    vector<int> leftmask(n), leftdup(n), leftparts(n);

    int mask = 0, dup = 0, parts = 1;
    for(int i = 0; i < n; i++) {
        int bit = 1 << (s[i] - 'a');
        dup |= mask & bit;
        mask |= bit;
        if(__builtin_popcount(mask) > k) {
            mask = bit;
            dup = 0;
            parts++;
        }
        leftmask[i] = mask;
        leftdup[i] = dup;
        leftparts[i] = parts;
    }

    int result = parts;
    mask = dup = parts = 0;

    for(int i = n - 1; i >= 0; i--) {
        int bit = 1 << (s[i] - 'a');
        dup |= mask & bit;
        mask |= bit;

        int bitcount = __builtin_popcount(mask);
        if(bitcount > k) {
            mask = bit;
            dup = 0;
            parts++;
            bitcount = 1;
        }

        if(bitcount == k) {
            if((bit & dup) && (bit & leftdup[i]) &&
              (__builtin_popcount(leftmask[i]) == k) &&
              ((leftmask[i] | mask) != 0x3FFFFFF)) {
                result = max(result, parts + leftparts[i] + 2);
              } else if(dup) {
                result = max(result, parts + leftparts[i] + 1);
              }
        }
    }

    cout << result << '\n';
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