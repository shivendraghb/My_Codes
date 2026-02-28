#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    int k;
    
    cin >> s;
    cin >> k;

    // count zeros;
    // int z = count(s.begin(), s.end(), '0');
    // int z = ranges::count(s, '0');

    // if (z == 0) { cout << 0 << '\n'; return; }
    // if (k == 1) { cout << z << '\n'; return; }
    // if (k > s.size()) { cout << -1 << '\n'; return; }
    // if (k == s.size()) { cout << (z == n ? 1 : -1) << '\n'; return; }

    // if (k % 2 == 0 && z % 2 == 1) { cout << -1 << '\n'; return; }

    // long long t = (z + k - 1) / k;

    // if ((t * k - z) % 2 != 0)
    //     t++;

    // cout << t << '\n';

    if (z == 0) { cout << 0 << '\n'; return; }

    int l = z, r = z;
    int steps = 0;

    unordered_steps<long long> visited;

    while (l <= r) {
        if (l == 0) return steps;

        long long state = ((long long)l << 32) | r;
        if (visited.count(state)) return -1;
        visited.insert(state);

        int next_l, next_r;

        if (k >= l && k <= r)
            next_
    }
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