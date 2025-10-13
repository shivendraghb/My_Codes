#include<bits/stdc++.h>
using namespace std;

#define int long long

int minswapstosort(vector<int>& arr, bool descending = false) {
    int n = arr.size();
    vector<pair<int, int>> v(n);

    for(int i = 0; i < n; i++) v[i] = {arr[i], i};

    if(descending)
        sort(v.rbegin(), v.rend());
    else
        sort(v.begin(), v.end());

    vector<bool> seen(n, false);
    int swaps = 0;

    for(int i = 0; i < n; i++) {
        if(seen[i] || v[i].second == i) continue;

        int size = 0;
        int j = i;

        while(!seen[j]) {
            seen[j] = true;
            j = v[j].second;
            size++;
        }
        if(size > 1)
            swaps += (size - 1);
    }

    return swaps;
}

int lilyshomework(vector<int>& v) {
    int asc = minswapstosort(v, false);
    int desc = minswapstosort(v, true);

    return min(asc, desc);
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int ans = lilyshomework(v);

    cout << ans << '\n';
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