#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    long long n;
    cin >> n;

    if(n <= 0) {cout << "false" << '\n'; return;}
    //use base change no function like log3

    double l = log(n);
    cout << "l = " << l << '\n';
    double lb3 = log(3.0);
    cout << "lb3 = " << lb3 << '\n';

    double log3_n = l / lb3;
    cout << "log3_n = " << log3_n << '\n';

    /*
        due to floating point precision something like
        4.99999999 and 5.00000001 won't be ewual in the if condition
        so to avoid this :
        => use round the log3_n and take the floating absolute difference
        => and if this difference is less than 10^-10 we can consider it close enough
    */

    if(fabs(log3_n - round(log3_n)) < 1e-10) cout << "true" << '\n';
    else cout << "false" << '\n';

    /*
        another approach could be a simple while loop
        that checks the divisibilty of n by n
        and if n reches to 1, so the number is a power of n;
    */

    // if(n <= 0) cout << "false" << '\n';

    // while(n % 3 == 0)
    //     n /= 3;

    // if(n == 1) cout << "true" << '\n';
    // else cout << "false" << '\n';
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
