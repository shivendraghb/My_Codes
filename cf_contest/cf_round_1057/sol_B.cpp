
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t; cin >> t;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        bool ok = true;
        for (int i = 0; i < 31; i++) {
            int bx = (x >> i) & 1;
            int by = (y >> i) & 1;
            int bz = (z >> i) & 1;
 
            // check if (bx, by, bz) is one of valid patterns
            if (!(
                (bx==0 && by==0 && bz==0) ||
                (bx==0 && by==1 && bz==0) ||
                (bx==0 && by==0 && bz==1) ||
                (bx==1 && by==0 && bz==0) ||
                (bx==1 && by==1 && bz==1)
            )) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}