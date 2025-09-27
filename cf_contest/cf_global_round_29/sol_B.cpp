#include <bits/stdc++.h>
using namespace std;

#define int long long

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int T;
//     if (!(cin >> T)) return 0;
//     while (T--) {
//         int n; cin >> n;
//         int m = 2 * n;
//         vector<int> ans(m + 1, 0); // 1-indexed

//         for (int x = n; x >= 1; --x) {
//             bool placed = false;
//             // try each residue class modulo x
//             for (int r = 1; r <= x; ++r) {
//                 int cnt = 0;
//                 int first = -1, second = -1;
//                 for (int pos = r; pos <= m; pos += x) {
//                     if (ans[pos] == 0) {
//                         if (cnt == 0) first = pos;
//                         else if (cnt == 1) second = pos;
//                         ++cnt;
//                         if (cnt == 2) break;
//                     }
//                 }
//                 if (cnt >= 2) {
//                     ans[first] = x;
//                     ans[second] = x;
//                     placed = true;
//                     break;
//                 }
//             }
//             // Problem guarantee: a solution always exists, so placed must be true.
//             // As a safety fallback (should not happen), but we keep it just in case.
//             if (!placed) {
//                 // If we somehow fail (shouldn't), put something sensible and continue.
//                 // This branch won't be taken on correct inputs per problem statement.
//                 // Fill remaining zeros with 1 (fallback).
//                 for (int i = 1; i <= m; ++i) if (ans[i] == 0) ans[i] = 1;
//             }
//         }

//         // Output
//         for (int i = 1; i <= m; ++i) {
//             if (i > 1) cout << ' ';
//             cout << ans[i];
//         }
//         cout << '\n';
//     }
//     return 0;
// }
void solve() {
    int n;
    cin >> n;

    for(int i = n; i >= 1; i--) {
        cout << i << " ";
    }
    cout << n << " ";

    for(int i = 1; i < n; i++) {
        cout << i << " ";
    }
    cout << endl;
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
