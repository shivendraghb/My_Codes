#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; ll k;
        cin >> n >> k;
        vector<ll> S(n), T(n);
        for (int i = 0; i < n; ++i) cin >> S[i];
        for (int i = 0; i < n; ++i) cin >> T[i];

        auto canon = [&](ll x) -> ll {
            ll r = x % k;
            if (r == 0) return 0;
            return min(r, k - r);
        };

        vector<ll> Cs(n), Ct(n);
        for (int i = 0; i < n; ++i) Cs[i] = canon(S[i]);
        for (int i = 0; i < n; ++i) Ct[i] = canon(T[i]);

        sort(Cs.begin(), Cs.end());
        sort(Ct.begin(), Ct.end());

        cout << (Cs == Ct ? "YES\n" : "NO\n");
    }
    return 0;
}