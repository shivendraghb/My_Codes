#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<array<int, 3>> casinos(n); // {li, ri, reali}
    for (int i = 0; i < n; ++i)
        cin >> casinos[i][0] >> casinos[i][1] >> casinos[i][2];

    vector<bool> used(n, false);
    int coins = k;

    while (true) {
        int best_gain = -1;
        int best_idx = -1;

        for (int i = 0; i < n; ++i) {
            if (!used[i] && casinos[i][0] <= coins && coins <= casinos[i][1]) {
                if (casinos[i][2] > best_gain) {
                    best_gain = casinos[i][2];
                    best_idx = i;
                }
            }
        }

        if (best_idx == -1) break;

        coins = best_gain;
        used[best_idx] = true;
    }

    cout << coins << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
