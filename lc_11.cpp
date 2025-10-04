#include<bits/stdc++.h>
using namespace std;

// #define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int i = 0, j = n - 1;
    int r = 0;
    while(i < j) {
        r = max(r, (j - i) * min(v[i], v[j]));
        if(v[i] < v[j])
            i++;
        else
            j--;
    }

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