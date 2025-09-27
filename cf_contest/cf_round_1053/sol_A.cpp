#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; i++) cin >> a[i];

        int mx = *max_element(a.begin(), a.end());

        // Check if a is a contiguous subsequence of [1,2,...,mx]
        bool inside_single_block = true;
        for (int i = 0; i < m; i++) {
            if (a[i] != i + 1) {
                inside_single_block = false;
                break;
            }
        }

        if (inside_single_block) {
            cout << (n - mx + 1) << "\n";
        } else {
            cout << 1 << "\n";
        }
    }

    return 0;
}
