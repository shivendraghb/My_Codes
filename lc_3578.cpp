#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1'000'000'007;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n = 0): n(n), bit(n + 1, 0) {}
    void add(int i, int delta) {
        while (i <= n) { bit[i] = (bit[i] + delta) % MOD; i += i & -i; }
    }

    int sumPrefix(int i) {
        ll s = 0;
        while (i > 0) { s += bit[i]; i -= i & i; }
        return (int)(s % MOD);
    }

    int rangeSum(int l, int r) {
        if (l > r) return 0;
        int res = (sumPrefix(r) - sumPrefix(l - 1)) % MOD;
        if (res < 0) res += MOD;
        return res;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int LOG = 1;
    while ((1<<LOG) <= n) LOG++;
    
    vector<vector<int>> stMin(LOG, vector<int>(n));
    vector<vector<int>> stMax(LOG, vector<int>(n));

    for (int i = 0; i < n; i++) {
        stMin[0][i] = v[i];
        stMax[0][i] = v[i]; 
    }

    for (int p = 1; p < LOG; p++) {
        int len = 1 << p, half = 1 << (p - 1);
        for (int i = 0; i + len - 1 < n; i++) {
            stMin[p][i] = min(stMin[p - 1][i], stMin[p - 1][i + half]);
            stMax[p][i] = max(stMax[p - 1][i], stMax[p - 1][i + half]);
        }
    }

    auto rangeMin = [&](int L, int R) {
        int len = R - L + 1;
        int p = 31 - __builtin_clz(len);
        return min(stMin[p][L], stMin[p][R - (1<<p) + 1]);
    };

    auto rangeMax = [&](int L, int R) {
        int len = R - L + 1;
        int p = 31 - __builtin_clz(len);
        return max(stMin[p][L], stMin[p][R - (1<<p) + 1]);
    };

    Fenwick bit(n + 1);
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    bit.add(1, 1);

    for (int i = 1; i <= n; i++) {
        int lo = 1, hi = i, ans = i + 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int mn = rangeMin(mid - 1, i - 1);
            int mx = rangeMax(mid - 1, i - 1);
            if ((ll)mx - mn <= k) {
                ans = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }
        if (ans == i + 1)
            dp[i] = 0;
        else
            dp[i] = bit.rangeSum(ans, i);

        bit.add(i + 1, dp[i]);
    }

    cout << dp[n] << '\n';
}

// void solve() {
//     int n, k;
//     cin >> n >> k;

//     vector<int> v(n);
//     for(int i = 0; i < n; i++)
//         cin >> v[i];

//     vector<int> dp(n + 1, 0), pref(n + 1, 0);
//     dp[0] = 1; pref[0] = 1;
//     deque<int> dqMin, dqMax;
//     int l = 1;

//     for(int r = 1; r <= n; r++) {
//         int val = v[r - 1];

//         while(!dqMin.empty() && v[dqMin.back() - 1] >= val)
//             dqMin.pop_back();
//         dqMin.push_back(r);

//         while(!dqMax.empty() && v[dqMax.back() - 1] <= val)
//             dqMax.pop_back();
//         dqMax.push_back(r);

//         while(l <= r &&v[dqMax.front() - 1] - v[dqMin.front() - 1] > k) {
//             if (!dqMin.empty() && dqMin.front() == l) dqMin.pop_front();
//             if (!dqMax.empty() && dqMax.front() == l) dqMax.pop_front();
//             l++;
//          }

//          int leftPrefIndex = l - 2;
//          ll add = pref[r - 1];
//          if (leftPrefIndex >= 0) add = (add - pref[leftPrefIndex] + MOD) % MOD;
//          dp[r] = (int)add;
//          pref[r] = (pref[r - 1] + dp[r]) % MOD;
//     }

//     cout << dp[n] << '\n';
// }

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