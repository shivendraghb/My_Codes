#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    bool louise = true;
    // do until n is not a power of 2
    while(fabs(floor(log2(n)) - log2(n)) > 0.001) {
        n -= pow(2, floor(log2(n)));
        louise = !louise;
    }

    //once n is a power of 2, so n is going to be halved only
    //at each turn

    //if log2(n) is odd then the number of moves left is odd
    //meaning turn ownership flips, so we flip louise
    if((int)log2(n) % 2 == 1)
        louise = !louise;

    //if louise == true after all moves -> it means Richard wins
    //since the turn flipped on the last move
    if(louise)
        cout << "Richard" << '\n';
    else
        cout << "Louise" << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}
