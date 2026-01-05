#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    const int MOD = 1e9 + 7;
    long long aba = 6; // r1 : aba pattern
    long long abc = 6; // r1 : abc pattern

    for (int i = 2; i <= n; i++) {
        long long new_aba = (aba * 3 + abc * 2) % MOD;
        long long new_abc = (aba * 2 + abc * 2) % MOD;

        aba = new_aba;
        abc = new_abc;
    }

    cout << (aba + abc) % MOD << '\n';

    // f(i) = 5 * f(i-1) - 2 * f(i-2)
    if (n == 1) { cout << 12 << '\n'; return; }
    // Base case: n = 2
    // f(2) : a2 = 3(6) + 2(6) = 30
    //        b2 = 2(6) + 2(6) = 24
    // Total f(2) = 54

    long long f_prev2 = 12; //f(1)
    long long f_prev1 = 54; //f(2)
    long long MOD1 = 1e9 + 7;

    for (int i = 3; i <= n; i++) {
        long long curr = (5 * f_prev1 - 2 * f_prev2) % MOD1;

        if (curr < 0) curr += MOD1;

        f_prev2 = f_prev1;
        f_prev1 = curr;
    }

    cout << f_prev1 << '\n';
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