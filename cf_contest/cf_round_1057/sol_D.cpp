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

        // check if all equal
        bool all_equal = true;
        for (int i = 1; i < n; i++)
            if (a[i] != a[0]) all_equal = false;
        if (all_equal) {
            cout << 0 << "\n";
            continue;
        }

        vector<int> lengths;
        int cnt = 1;
        // create linear blocks of consecutive equal elements
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) cnt++;
            else {
                lengths.push_back(cnt);
                cnt = 1;
            }
        }
        lengths.push_back(cnt);

        // handle circular merge if first and last blocks equal
        if (a[0] == a[n - 1] && lengths.size() > 1) {
            lengths[0] += lengths.back();
            lengths.pop_back();
        }

        long long ans = 0;
        for (int len : lengths) {
            if (len == 1) ans += 1;       // single element block needs 1 op
            else ans += len / 2;          // ceil(len/2) ops = len/2 for even, len/2 + 1 for odd
            if (len % 2 == 1 && len > 1) ans++; // add 1 for odd-length blocks >1
        }

        cout << ans << "\n";
    }
    return 0;
}
