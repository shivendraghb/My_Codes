#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    //The set of possible amounts of water is  exactly the set
    //of multiples of gcd(a,b)

    //so if c is not divisible by gcd(a,b) it is impossible to measure it

    if(c <= max(a, b) && c % __gcd(a, b) == 0)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
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
