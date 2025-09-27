#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    //these bozos have not even defined the problem well enough
    //at first i thought of implementing next permutation
    //maybe i am being a bozo

    // total pairs = m * n
    // so exactly half of them would be with different pairity
    // so get like m * n / 2

    //for Alice to win
    //check for only even and odd
    //Alice wins one lane has an odd number of flowers
    //and the other lane has an even number

    long long r = n * m / 2;

    cout << r << '\n';
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
