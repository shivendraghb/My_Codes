#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

// Precompute factorials and inverses for combinations
static const int MAX = 400000;
long long fact[MAX+1], invfact[MAX+1];

long long modexp(long long a, long long e=MOD-2) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

long long C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i <= MAX; i++) fact[i] = fact[i-1] * i % MOD;
    invfact[MAX] = modexp(fact[MAX]);
    for (int i = MAX; i > 0; i--) invfact[i-1] = invfact[i] * i % MOD;

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        long long ans = 0;

        // Precompute prefix sums of compositions up to m.
        vector<long long> dp_count(m+1), dp_sum(m+1);
        for (int t = 0; t <= m; t++) {
            int S = m - t;
            if (t == 0) {
                dp_count[t] = (S == 0);
                dp_sum[t] = 0;
            } else {
                // Count compositions: C(S + n - 2, n - 2)
                dp_count[t] = C(S + n - 2, n - 2);
                // Sum of all elements over these compositions:
                // On average, each of n-1 spots has sum = S, so total elements sum = S * dp_count[t] * inv(n-1)
                long long invn = modexp(n - 1);
                dp_sum[t] = dp_count[t] * (long long)S % MOD * invn % MOD * (n-1) % MOD;
            }

            long long contrib = (dp_count[t] * (long long)(n - 1) % MOD * t % MOD - dp_sum[t] + MOD) % MOD;
            ans = (ans + contrib) % MOD;
        }

        cout << ans << "\n";
    }
    return 0;
}