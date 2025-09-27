#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);

    for(auto &x : v)
        cin >> x;
    //PURPOSE:
    //std::upper_bound returns an iterator
    //pointing to the first element in the specified range [first, last)
    //that is strictly greater than the given value.

    //REQUIREMENTS:
    // The range must be sorted in non-descending order
    //for std::upper_bound to work correctly and efficiently
    //(it uses a binary search algorithm internally).
    auto it = upper_bound(v.begin(), v.end(), 30);

    int idx = distance(v.begin(), it);

    cout << "Vector elements:" << '\n';
    for(const auto &x : v)
        cout << x << " ";
    cout << '\n';

    cout << "idx greater than 30 is : " << idx << " element: " << v[idx] << '\n';
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
