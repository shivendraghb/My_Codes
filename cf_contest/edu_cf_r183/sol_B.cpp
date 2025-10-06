#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
 
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (char c : s) {
            if (c == '0') cnt0++;
            else if (c == '1') cnt1++;
            else cnt2++;
        }
 
        int left_min = cnt0;
        int left_max = cnt0 + cnt2;
        int right_min = cnt1;
        int right_max = cnt1 + cnt2;
 
        int r = n - k; // number of cards that remain
 
        // Special case: no cards remain
        if (r == 0) {
            cout << string(n, '-') << '\n';
            continue;
        }
 
        int L_low = max(left_min, k - right_max);
        int L_high = min(left_max, k - right_min);
 
        // If no feasible L (shouldn't happen with valid input), treat as all removed
        if (L_low > L_high) {
            cout << string(n, '-') << '\n';
            continue;
        }
 
        int U_L = L_low + 1;
        int U_R = L_high + r;           // n - k + L_high (same)
        int G_L = L_high + 1;
        int G_R = L_low + r;           // n - k + L_low (same)
 
        string ans(n, '?');
        for (int i = 1; i <= n; ++i) {
            if (i < U_L || i > U_R) ans[i-1] = '-';
            else if (i >= G_L && i <= G_R) ans[i-1] = '+';
            else ans[i-1] = '?';
        }
 
        cout << ans << '\n';
    }
    return 0;
}