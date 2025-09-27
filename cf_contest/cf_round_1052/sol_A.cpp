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

        map<int,int> freq;
        for (int x : a) freq[x]++;

        int maxFreq = 0;
        for (auto [_, f] : freq) maxFreq = max(maxFreq, f);

        int ans = 0;
        for (int f = 1; f <= maxFreq; f++) {
            int cnt = 0;
            for (auto [_, c] : freq) {
                if (c >= f) cnt++;
            }
            ans = max(ans, f * cnt);
        }

        cout << ans << "\n";
    }
    return 0;
}
