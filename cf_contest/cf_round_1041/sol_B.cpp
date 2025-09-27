#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;

    x--;

    int walls_left = 0;
    for (int i = 0; i < x; ++i) {
        if (s[i] == '#') {
            walls_left++;
        }
    }

    int walls_right = 0;
    for (int i = x + 1; i < n; ++i) {
        if (s[i] == '#') {
            walls_right++;
        }
    }

    if (walls_left == 0 || walls_right == 0) {
        cout << 1 << '\n';
    } else {
        int cells_left = x;
        int cells_right = n - x - 1;
        cout << min(cells_left, cells_right) + 1 << '\n';
    }
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
