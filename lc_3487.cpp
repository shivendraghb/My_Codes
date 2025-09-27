#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // use set to maintain uniqueness and sorted order
    // non-increasing order to maximize the sum
    // ignore negatives
    // list can be all negatives so ignoring won't work
    // -> pick greedily
    // can check for the abs of sum to increase with current element

    set<int, greater<int>> s(a.begin(), a.end());

    int first = *s.begin();
    if(first < 0) cout << first << '\n';

    else{
        int sum = 0;
        for(int i : s)
            if(i > 0)
                sum += i;

        cout << sum << '\n';
    }
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
