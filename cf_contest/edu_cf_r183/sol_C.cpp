#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
 
        int total_diff = 0; // a -> +1, b -> -1
        for (char c : s) total_diff += (c == 'a' ? 1 : -1);
 
        if (total_diff == 0) {
            cout << 0 << '\n';
            continue;
        }
 
        unordered_map<int,int> last; // prefix sum -> latest index (0..n)
        last.reserve(n * 2);
        last[0] = 0; // prefix sum 0 at index 0 (before any chars)
 
        int prefix = 0;
        int ans = n + 1;
        for (int i = 0; i < n; ++i) {
            prefix += (s[i] == 'a' ? 1 : -1); // prefix at index i+1
            int need = prefix - total_diff;  // we need some prefix[i] == need
 
            // check if a suitable previous prefix exists (latest occurrence stored)
            auto it = last.find(need);
            if (it != last.end()) {
                ans = min(ans, (i + 1) - it->second); // length = (j - i)
            }
 
            // update last occurrence of this prefix (store index i+1)
            last[prefix] = i + 1;
        }
 
        // If no subarray found or the minimum length is n (removing whole string), print -1
        if (ans == n + 1 || ans == n) cout << -1 << '\n';
        else cout << ans << '\n';
    }
    return 0;
}