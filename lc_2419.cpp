#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int m = *max_element(a.begin(), a.end());

    int max_l = 0, l = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == m) {
            l++;
            max_l = max(max_l, l);
        } else
            l = 0;
    }

    cout << max_l << '\n';
}

int32_t main() {

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
