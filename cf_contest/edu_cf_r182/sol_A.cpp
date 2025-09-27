#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // Prefix sums
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + a[i];

        bool found = false;
        for (int l = 1; l < n; l++) {
            for (int r = l + 1; r < n; r++) {
                int s1 = prefix[l] % 3;
                int s2 = (prefix[r] - prefix[l]) % 3;
                int s3 = (prefix[n] - prefix[r]) % 3;

                if (s1 == s2 && s2 == s3) { // all equal
                    cout << l << " " << r << "\n";
                    found = true;
                    break;
                }
                if (s1 != s2 && s1 != s3 && s2 != s3) { // all distinct
                    cout << l << " " << r << "\n";
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (!found) cout << "0 0\n";
    }

    return 0;
}
