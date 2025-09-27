#include<bits/stdc++.h>
using namespace std;

#define int long long

bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    vector<bool> covered(right - left + 1, false);
    for(auto& range : ranges) {
        int l = max(range[0], left);
        int r = min(range[1], right);

        for(int i = l; i <= r; i++)
            covered[i - left] = true;
    }

    for(bool c : covered)
        if(!c) return false;

    return true;
}

void solve() {
    int n;
    cin >> n;

    int left, right;
    cin >> left >> right;

    vector<vector<int>> ranges(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cin >> ranges[i][0] >> ranges[i][1];
    }

    cout << isCovered(ranges, left, right) << '\n';
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
