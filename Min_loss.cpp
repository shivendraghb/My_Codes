#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    // set<long> prev;
    // long minLoss = LONG_MAX;

    // for(long p : v) {
    //     long ng = *prev.upper_bound(p);// log(n)
    //     //here upper_bound worked like this(syntax)
    //     //cause prev is a set and it has member functions
    //     //lower_bound() and upper_bound() because
    //     //it’s an ordered associative container (internally a balanced BST).

    //     //for vector,array it should be
    //     //auto it = upper_bound(v.begin(), v.end(), value);
    //     long loss = ng - p;
    //     if(loss > 0 && loss < minLoss)
    //         minLoss = loss;

    //     prev.insert(p);// log(n)
    // }// nlog(n)

    // // vector<pair<long, int>> vp;
    // // for(int i = 0; i < n; i++) vp.push_back({v[i], i});
    // // sort(v.begin(), v.end());
    // // long minLoss = LONG_MAX;
    // // for(int i = 0; i < n - 1; i++) {
    // //     if(vp[i].second < vp[i + 1].second) {
    // //         minLoss = min(minLoss, vp[i].first - vp[i + 1].first);
    // //     }
    // // }

    // cout << minLoss << '\n';
    int r = INT_MAX;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int loss = v[i] - v[j];
            if(loss > 0 && loss < r)
                r = loss;
        }
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
