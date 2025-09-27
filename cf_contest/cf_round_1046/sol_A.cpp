#include <bits/stdc++.h>
using namespace std;

bool ok(long long x, long long y) {
    long long L = max(x, y), S = min(x, y);
    return L <= 2 * (S + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if(!(cin >> t)) return 0;
    while (t--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        long long x1 = a, y1 = b;         // first half
        long long x2 = c - a, y2 = d - b; // second half (increments)

        cout << (ok(x1, y1) && ok(x2, y2) ? "YES" : "NO") << '\n';
    }
    return 0;
}
