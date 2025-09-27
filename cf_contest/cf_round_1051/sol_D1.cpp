#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while(T--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int M = n;
        int SZ = (M+1) * (M+1);
        auto idx = [&](int x, int y){ return x*(M+1) + y; };

        vector<ll> dp(SZ, 0), ndp(SZ, 0);
        dp[idx(0,0)] = 1;

        for(int x : a) {
            fill(ndp.begin(), ndp.end(), 0);
            for(int l1 = 0; l1 <= M; l1++) {
                for(int l2 = 0; l2 <= M; l2++) {
                    ll cur = dp[idx(l1,l2)];
                    if(!cur) continue;
                    ndp[idx(l1,l2)] = (ndp[idx(l1,l2)] + cur) % MOD;
                    if(x >= l1) {
                        ndp[idx(x,l2)] = (ndp[idx(x,l2)] + cur) % MOD;
                    } else if (x >= l2) {
                        ndp[idx(l1,x)] = (ndp[idx(l1,x)] + cur) % MOD;
                    }
                }
            }
            dp.swap(ndp);
        }

        ll ans = 0;
        for (ll v : dp) {
            ans += v;
            if (ans >= MOD) ans -= MOD;
        }
        cout << (ans % MOD) << '\n';
    }

    return 0;
}
