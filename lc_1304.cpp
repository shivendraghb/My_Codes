#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> r1(n);

    if(n == 1){cout << 1 << '\n'; return;}
    if(n == 2){cout << "1 -1" << '\n'; return;}
    if(n == 3){cout << "-1 0 1" << '\n'; return;}

    /*
        S = n(n+1)/2
        n -> n-1
        S = n(n-1)/2
        choose -S
        a_0 = n(1-n)/2
        total sum = -S + S = 0
    */
    r1[0] = n * (1 - n) / 2;
    for(int i = 1; i < n; i++) {
        r1[i] = i;
    }

    for(int i : r1)
        cout << i << " ";
    cout << '\n';

    /*
        Symmetric Approach:

        AP : arithmetic progression
        sum of ap = (a_0 + a_n-1)*n/2
        for S = 0:
            a_0 + a_n-1 = 0
            since, a_n-1 = a_0 + (n-1)d

        so, a_n-1 - a_0 = (n-1)d = -2a_0

        choosing d:
            from : (n-1)d = -2a_0
            d = 2, a_0 = 1-n

        General formula:
            A[i] = a_0 + id
                 = (1-n) + 2i
                 = 2i - n + 1
    */

    vector<int> r2(n);
    for(int i = 0; i < n; i++)
        r2[i] = 2 * i - n + 1;

    for(int i : r2)
        cout << i << " ";

    cout << '\n';
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
