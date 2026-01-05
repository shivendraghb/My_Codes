#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Data {
    long long profit = 0, buy = 0, sell = 0;
    Data(long long profit = 0, long long buy = 0, long long sell = 0):
        profit(profit), buy(buy), sell(sell) {}
};
Data dp[1000][501];

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    // const int x0 = p[0];
    // fill (dp[0], dp[0] + (k + 1), Data(0, -x0, x0));
    // for (int i = 1; i < n; i++) {
    //     const int x = p[i];
    //     for (int t = 1; t <= k; t++) {
    //         auto [p , b, s] = dp[i - 1][t];
    //         const long long prevP = dp[i - 1][t - 1].profit;
    //         p = max(p, max(b + x, s - x));
    //         b = max(b, prevP - x);
    //         s = max(s, prevP + x);
    //         dp[i][t] = Data(p, b, s);
    //     }
    // }    

    // cout << dp[n - 1][k].profit << '\n';

    if (n == 0) { cout << 0 << '\n'; return; }
    vector<long long> dp0(k + 1, 0), dp1(k + 1, LLONG_MIN / 4), dp2(k + 1, LLONG_MIN / 4);

    for (int price : p) {
        for (int j = k; j >= 1; j--) {
            dp0[j] = max ({dp0[j],
                           dp1[j] + price,
                           dp2[j] - price});

            dp1[j] = max(dp1[j],
                         dp0[j - 1] - price);

            dp2[j] = max(dp2[j], 
                         dp0[j - 1] + price);
        }
    }

    cout << dp0[k] << '\n';
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