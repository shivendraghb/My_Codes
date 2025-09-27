#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    /*
        Each element arr[i] appears in multiple subarrays.
        How many times does arr[i] appear in all subarrays?
        for an element at idx i:
            count[i] = (i + 1)x(n-i)
        i+1 = number of ways to choose a starting point ≤ i.
        n-i = number of ways to choose an ending point ≥ i.
        If count[i] is even, XORing arr[i] count[i] times = 0
        (because x ^ x = 0).
        If count[i] is odd, arr[i] contributes once to the final XOR.
    */

    if(n % 2 == 0) {cout << 0 << '\n'; return;}
    int r = 0;
    for(int i = 0; i < n; i += 2)
        r ^= v[i];

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
