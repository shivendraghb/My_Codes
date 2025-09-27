#include<bits/stdc++.h>
using namespace std;

// #define int long long

bool checkZero(int a, int b) {
    while(a > 0) {
        int rem = a % 10;
        if(rem == 0) return false;
        a /= 10;
    }
    while(b > 0) {
        int rem = b % 10;
        if(rem == 0) return false;
        b /= 10;
    }

    return true;
}

void solve() {
    int n;
    cin >> n;

    vector<int> r(2);

    for(int i = 1; i <= n; i++) {
        int a = i, b = n - i;
        if(a + b == n && checkZero(a, b)) {
            r[0] = a;
            r[1] = b;
            break;
        }
    }

    cout << r[0] << " " << r[1] << '\n';
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
