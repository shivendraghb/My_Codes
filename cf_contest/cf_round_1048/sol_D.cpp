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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        vector<int> badOdd(n + 1, 0), badEven(n + 1, 0);
        for (int i = 1; i + 2 <= n; i++) {
            if (a[i] > a[i + 2]) {
                if (i % 2 == 1) badOdd[i] = 1;
                else badEven[i] = 1;
            }
        }

        vector<int> prefOdd(n + 1, 0), prefEven(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefOdd[i] = prefOdd[i - 1] + badOdd[i];
            prefEven[i] = prefEven[i - 1] + badEven[i];
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            bool ok = true;
            if (l % 2 == 1) {
                // check odd subsequence [l..r]
                if (prefOdd[r - 2] - prefOdd[l - 1] > 0) ok = false;
                // check even subsequence [l+1..r]
                if (prefEven[r - 2] - prefEven[l] > 0) ok = false;
            } else {
                // even start
                if (prefEven[r - 2] - prefEven[l - 1] > 0) ok = false;
                if (prefOdd[r - 2] - prefOdd[l] > 0) ok = false;
            }
            cout << (ok ? "YES\n" : "NO\n");
        }
    }
    return 0;
}

// void solve() {
//     int n, q;
//     cin >> n >> q;

//     vector<int> a(n);
//     for(int i = 0; i < n; i++)
//         cin >> a[i];

//     vector<int> is_bad_even(n, 0);
//     vector<int> is_bad_odd(n, 0);

//     for(int i = 0; i < n - 2; i++) {
//         if(a[i] > a[i + 2]) {
//             if(i % 2 == 0)
//                 is_bad_even[i] = 1;
//             else
//                 is_bad_odd[i] = 1;
//         }
//     }

//     vector<long long> prefix_sum_even(n + 1, 0);
//     vector<long long> prefix_sum_odd(n + 1, 0);

//     for(int i = 0; i < n; i++) {
//         prefix_sum_even[i + 1] = prefix_sum_even[i] + is_bad_even[i];
//         prefix_sum_odd[i + 1] = prefix_sum_odd[i] + is_bad_odd[i];
//     }

//     while(q--) {
//         int l, r;
//         cin >> l >> r;

//         int i = 0, j = 0;
//         if(l % 2 == 0)
//             prefix_sum_even[i++] +=
//     }
// }
