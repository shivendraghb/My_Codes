#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void solve() {
    int n;
    cin >> n;
    long long max_sum = LLONG_MIN, max_diff = LLONG_MIN, min_diff = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        max_sum = max(max_sum, x + y);
        max_diff = max(max_diff, x - y);
        min_diff = min(min_diff, x - y);
    }

    long long k = 2000000000;

    cout << "? R " << k << endl;
    long long d1;
    cin >> d1;
    if (d1 == -1) return;

    cout << "? L " << 2 * k << endl;
    long long d2;
    cin >> d2;
    if (d2 == -1) return;

    cout << "? R " << 2 * k << endl;
    long long d3;
    cin >> d3;
    if (d3 == -1) return;

    long long initial_y = (d1 + d2 - 4 * k + max_sum - max_diff) / 2;
    long long initial_x = (d1 + d3 - 4 * k + max_sum + min_diff) / 2;

    cout << "! " << initial_x << " " << initial_y << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
