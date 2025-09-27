#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;

    cin >> ax1 >> ay1 >> ax2 >> ay2 >> bx1 >> by1 >> bx2 >> by2;

    int t_a = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);

    int x1 = max(ax1, bx1);
    int x2 = min(ax2, bx2);
    int y1 = max(ay1, by1);
    int y2 = min(ay2, by2);

    int a = max(0LL, x2 - x1) * max(0LL, y2 - y1);

    cout << t_a - a << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
