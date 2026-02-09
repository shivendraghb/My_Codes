#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    // deque<int> dq;
    // vector<int> res;

    // for(int i = 0; i < n; i++) {
    //     if(!dq.empty() && dq.front() == i - k)
    //         dq.pop_front();

    //     while(!dq.empty() && v[dq.back()] < v[i])
    //         dq.pop_back();

    //     dq.push_back(i);

    //     if(i >= k - 1)
    //         res.push_back(v[dq.front()]);
    // }

    // for(int x : res) cout << x << " ";

    // int OR = 0;
    
    // for(int mask = 0; mask < (1 << n); mask++) {
    //     if(__builtin_popcount(mask) == k) {
    //         int curr = 0;
    //         for(int i = 0; i < n; i++)
    //             if(mask & (1 << i)) curr |= v[i];

    //         OR = max(OR, curr);
    //     }
    // }

     for(int i = 0; i <= n - k; i++) {
        int e = *max_element(v.begin() + i, v.begin() + i + k);
        cout << e << " ";
    }
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