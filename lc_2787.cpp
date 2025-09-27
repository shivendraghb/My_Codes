#include<bits/stdc++.h>
using namespace std;

#define int long long

#define MOD 1000000007LL

int numberOfWays(int n, int x) {
    vector<int> powers;
    for(int i = 1; ;i++) {
        long long p = 1;

        for(int k = 0; k < x; k++) p *= i;

        if(p > n) break;
        powers.push_back((int)p);
    }

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for(int p : powers)
        for(int s = n; s >= p; s--)
            dp[s] = (dp[s] + dp[s - p]) % MOD;

    return (int)dp[n];
}

void solve() {
    int n, x;
    cin >> n >> x;

    cout << numberOfWays(n, x) << '\n';
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
