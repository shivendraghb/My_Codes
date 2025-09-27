#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // count total frequencies
        unordered_map<int, int> totalFreq;
        for (int x : a) totalFreq[x]++;

        // check divisibility
        bool possible = true;
        unordered_map<int, int> quota;
        for (auto [v, f] : totalFreq) {
            if (f % k != 0) {
                possible = false;
                break;
            }
            quota[v] = f / k;
        }

        if (!possible) {
            cout << 0 << "\n";
            continue;
        }

        // two pointers
        long long ans = 0;
        unordered_map<int, int> windowFreq;
        int l = 0;
        for (int r = 0; r < n; r++) {
            windowFreq[a[r]]++;

            // shrink if exceeds quota
            while (windowFreq[a[r]] > quota[a[r]]) {
                windowFreq[a[l]]--;
                l++;
            }

            // all subarrays ending at r are valid
            ans += (r - l + 1);
        }

        cout << ans << "\n";
    }
    return 0;
}
