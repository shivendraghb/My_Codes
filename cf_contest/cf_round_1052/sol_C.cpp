#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int first1 = -1, last1 = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (first1 == -1) first1 = i;
                last1 = i;
            }
        }

        // Check contiguity of 1's
        bool possible = true;
        if (first1 != -1) {
            for (int i = first1; i <= last1; i++) {
                if (s[i] != '1') possible = false;
            }
        }

        if (!possible) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        vector<int> perm;
        // Two options: 1s prefix or 1s suffix
        if (first1 == 0) {
            // 1s prefix
            for (int i = first1; i <= last1; i++) perm.push_back(i + 1);
            for (int i = last1 + 1; i < n; i++) if (s[i] == '0') perm.push_back(i + 1);
        } else if (last1 == n - 1) {
            // 1s suffix
            for (int i = 0; i < first1; i++) if (s[i] == '0') perm.push_back(i + 1);
            for (int i = first1; i <= last1; i++) perm.push_back(i + 1);
        } else {
            // Should not happen due to contiguity check
        }

        // Fill any remaining zeros not yet added
        for (int i = 0; i < n; i++) if (s[i] == '0' && find(perm.begin(), perm.end(), i + 1) == perm.end()) perm.push_back(i + 1);

        for (int i = 0; i < n; i++) {
            cout << perm[i] << (i + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
}
