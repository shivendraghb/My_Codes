#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<array<int, 3>> casinos(n); // {li, ri, reali}
    for (int i = 0; i < n; ++i)
        cin >> casinos[i][0] >> casinos[i][1] >> casinos[i][2];

    sort(casinos.begin(), casinos.end()); // sort by li

    priority_queue<pair<int, int>> pq; // max-heap: {reali, index}
    int coins = k;
    int i = 0;

    vector<bool> used(n, false);

    while (true) {
        // Push all casinos that are now accessible (li <= coins)
        while (i < n && casinos[i][0] <= coins) {
            pq.push({casinos[i][2], i});
            ++i;
        }

        bool played = false;

        while (!pq.empty()) {
            auto [real, idx] = pq.top();
            pq.pop();

            if (used[idx]) continue;

            // Check if still valid with current coins
            if (casinos[idx][1] >= coins) {
                coins = real;
                used[idx] = true;
                played = true;
                break;
            }
        }

        if (!played) break; // no more valid moves
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
