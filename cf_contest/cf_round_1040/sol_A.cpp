#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[1 << 20]; // Adjust based on max_val
vector<int> freq(51);
int max_val;

ll get_mex(int mask) {
    for (int i = 0; i <= max_val + 1; i++) {
        if (!(mask & (1LL << i))) return i;
    }
    return max_val + 2;
}

ll solve(int mask) {
    if (mask == 0) return 0;
    if (dp[mask] != -1) return dp[mask];
    ll res = 0;
    // Try all non-empty subsets of the mask
    for (int sub = mask; sub; sub = (sub - 1) & mask) {
        ll sum = 0;
        for (int i = 0; i <= max_val; i++) {
            if (sub & (1LL << i)) sum += (ll)i * freq[i];
        }
        ll mex = get_mex(sub);
        res = max(res, max(sum, mex) + solve(mask ^ sub));
    }
    return dp[mask] = res;
}

void solve_case() {
    int n;
    cin >> n;
    fill(freq.begin(), freq.end(), 0);
    max_val = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
        max_val = max(max_val, x);
    }
    memset(dp, -1, sizeof(dp));
    int mask = (1LL << (max_val + 1)) - 1;
    cout << solve(mask) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve_case();
    return 0;
}
