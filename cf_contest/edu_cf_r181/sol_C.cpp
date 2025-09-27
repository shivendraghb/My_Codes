#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(int n) {
    int bad = 0;

    int primes[] = {2, 3, 5, 7};

    for(int m = 1; m < (1 << 4); m++) {
        int lcm = 1, bits = 0;

        for(int i = 0; i < 4; i++) {
            if(m & (1 << i)) {
                lcm *= primes[i];
                bits++;
            }
        }

        if(bits % 2 == 1) bad += n / lcm;
        else bad -= n / lcm;
    }

    return n - bad;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;

        int ans = solve(r) - solve(l - 1);
        cout << ans << '\n';
    }

    return 0;
}
