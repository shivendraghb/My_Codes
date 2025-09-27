#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
//needed to download it
using namespace std;
using boost::multiprecision::cpp_int;

#define int long long

void solve() {
    cpp_int a, b;
    cin >> a >> b;

    if(a < 0) a -= a;
    if(b < 0) b -= b;

    while(b != 0) {
        cpp_int r = a % b;
        a = b;
        b = r;
    }

    cout << a << '\n';
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
