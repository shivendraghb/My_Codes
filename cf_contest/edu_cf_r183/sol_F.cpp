#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Compute minimum number of turns to reach m
ll minTurns(int n, ll m, vector<int>& a, vector<int>& b) {
    ll pos = 0; // current position
    ll turn = 0; // total turns

    // Precompute the maximum safe moves for each trap type
    vector<int> nextTrap(n, 0);
    while (pos < m) {
        int trapType = turn % n;
        // check if current cell is unsafe
        if ((pos % a[trapType]) == b[trapType]) {
            // wait 1 turn
            turn++;
            continue;
        }
        // move 1 cell safely
        pos++;
        turn++;
    }
    return turn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll m;
        cin >> n >> m;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        ll ans = minTurns(n, m, a, b);
        cout << ans << "\n";
    }

    return 0;
}