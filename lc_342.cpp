#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    if(n <= 0) {
        cout << "false" << '\n';
        return;
    }

    double l = log(n);
    double lb4 = log(4.0);

    double log4_n = l / lb4;

    if(fabs(log4_n - round(log4_n)) < 1e-10)
        cout << "true" << '\n';
    else
        cout << "false" << '\n';

    if(n <= 0) cout << "false" << '\n';
    if(n == 1) cout << "true" << '\n'
    if(n % 4 != 0) cout << "false" << '\n';

    while(n > 0) {
        n /= 4;
        if(n == 1) cout << "true" << '\n'
        else if(n % 4 != 0) cout << "false" << '\n';
    }
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
