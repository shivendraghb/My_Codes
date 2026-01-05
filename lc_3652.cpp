#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 1;-
long long sum[N] = {0};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    
    vector<int> s(m);
    for (int i = 0; i < m; i++)
        cin >> s[i];

    int k2 = k / 2;
    long long modify = 0;
    for (int i = 0; i < n; i++) {
        const int x = p[i];
        sum[i + 1] = sum[i] + s[i] * x;
        modify += (-(i >= k2 & i < k) & x);
    }

    long long profit = max(sum[n], modify + sum[n] - sum[k]);

    for (int i = 1; i + k <= n; i++) {
        modify += p[i + k - 1] - p[i + k2 - 1];
        profit = max(profit, modify + sum[n] - sum[i + k] + sum[i]);
    }

    cout << profit << '\n';
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