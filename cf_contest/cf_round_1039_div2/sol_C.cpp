#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    long long min_so_far = b[0];
    bool possible = true;

    for (int i = 1; i < n; i++) {
        if (b[i] < min_so_far) {
            possible = false;
            break;
        }
        min_so_far = min(min_so_far, b[i]);
    }

    cout << (possible ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
