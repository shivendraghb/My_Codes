#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        // Current OR
        long long currOR = 0;
        for (auto x : a) currOR |= x;

        vector<long long> minCost; // cost to set currently 0 bits in OR

        for (int k = 0; k <= 30; ++k) {
            if ((currOR >> k) & 1) continue; // already set
            long long bitVal = 1LL << k;
            long long best = LLONG_MAX;
            for (auto x : a) {
                if ((x >> k) & 1) { best = 0; break; } // already 1 in this number
                long long cost = bitVal - (x % bitVal);
                best = min(best, cost);
            }
            minCost.push_back(best);
        }

        sort(minCost.begin(), minCost.end()); // smallest cost first

        while (q--) {
            long long b;
            cin >> b;
            int res = __builtin_popcountll(currOR);
            for (auto c : minCost) {
                if (b >= c) {
                    b -= c;
                    res++;
                } else break;
            }
            cout << res << "\n";
        }
    }
    return 0;
}
