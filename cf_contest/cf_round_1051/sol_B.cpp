#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector<int> b(k);
        for (int i = 0; i < k; ++i) cin >> b[i];

        sort(a.begin(), a.end());           // ascending
        sort(b.begin(), b.end());           // ascending

        ll total = 0;
        for (ll x : a) total += x;

        ll freebies = 0;
        int r = n - 1;

        for (int i = 0; i < k; ++i) {
            int x = b[i];
            if (x == 1) {
                if (r < 0) break;
                freebies += a[r];
                r -= 1;
            } else {
                if (r - (x - 1) < 0) break; // not enough items left to form a group of size x
                freebies += a[r - (x - 1)];
                r -= x;
            }
        }

        cout << (total - freebies) << '\n';
    }
    return 0;
}
