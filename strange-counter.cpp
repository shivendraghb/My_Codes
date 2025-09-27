#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    //get the starting pos
    //need to update the start pos until (t > start)
    //start increases by a factor of 2
    int start_time = 3, inc = 3;

    while(n > start_time) {
        inc *= 2;
        start_time += inc;
    }

    cout << start_time - n + 1 << '\n';
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
