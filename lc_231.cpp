#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    double l = log2(n);

    if(l == (int)l)
        cout << "true" << '\n';
    else
        cout << "false" << '\n';
}

int32_t main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int t;
    cin >> t;

    for(int i = 0; i <= 10; i++)
        cout << pow(2, i) << '\n';
    //cout.flush();

    while(t--) {
        solve();
    }

    return 0;
}
