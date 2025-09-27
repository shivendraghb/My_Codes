#include<bits/stdc++.h>
using namespace std;

#define int long long// int data type converted to long long
                    //throughout the code  why?
//cause in competetive programming test cases can be very large
//so it hectic to erite long long every time so
//better drfine int to long long

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
//ios => input output steam
//c and c++ share similar output stream/buffer
//but c's output stream is slow
// what  is the work of sync
//stdio? remeber c has stdio and c++ has iostream
//but internally both are very much similar and connected
//stdio(c's output stram is very slow)
//this effects runtime in CP
//so better disconnect from it
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
