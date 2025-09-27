#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> f(n), b(n);
    for (int i = 0; i < n; ++i) cin >> f[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    // Map: basket_capacity -> set of indices (ordered)
    map<int, set<int>> cap_to_indices;
    for (int i = 0; i < n; ++i) {
        cap_to_indices[b[i]].insert(i);
    }

    int last_used_index = -1;
    int unplaced = 0;

    for (int i = 0; i < n; ++i) {
        bool placed = false;

        // Try all capacities >= f[i]
        for (auto it = cap_to_indices.lower_bound(f[i]); it != cap_to_indices.end(); ++it) {
            // From these, try to find leftmost available index >= i
            auto& indices = it->second;
            auto idx_it = indices.lower_bound(i); // find first available basket with index >= i

            if (idx_it != indices.end()) {
                indices.erase(idx_it); // use the basket
                if (indices.empty()) cap_to_indices.erase(it); // cleanup
                placed = true;
                break;
            }
        }

        if (!placed) unplaced++;
    }

    cout << unplaced << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
