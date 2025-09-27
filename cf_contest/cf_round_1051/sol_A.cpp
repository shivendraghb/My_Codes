#include <bits/stdc++.h>
using namespace std;

bool solve(const vector<int>& p, int n) {
    int pos = find(p.begin(), p.end(), n) - p.begin(); // position of n (0-based)
    int L = pos, R = pos;
    for (int need = n - 1; need >= 1; --need) {
        if (L > 0 && p[L - 1] == need) {
            --L;
        } else if (R < n - 1 && p[R + 1] == need) {
            ++R;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i];
        cout << (solve(p, n) ? "YES\n" : "NO\n");
    }
    return 0;
}
