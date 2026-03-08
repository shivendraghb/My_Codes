#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string word;
    cin >> word;

    int n = word.size();
    int ans = 0;

    for (int i = 1; i < n; ) {
        if (abs(word[i] - word[i-1]) <= 1) {
            ans++;
            i += 2;
        } else {
            i++;
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}