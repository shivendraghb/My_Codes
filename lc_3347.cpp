#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k, numOperations;
    cin >> n >> k >> numOperations;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    auto maxFrequencyOfArrayVal = [&](const vector<int>& v) {
        unordered_map<int, int> count;
        for(int val : v) count[val]++;

        int maxFreq = 0;

        for(auto& [val, cnt] : count) {
            int l = lower_bound(v.begin(), v.end(), val - k) - v.begin();
            int r = upper_bound(v.begin(), v.end(), val + k) - v.begin() - 1;
            int freq = min(r - l + 1, numOperations + cnt);
            maxFreq = max(maxFreq, freq);
        }

        return maxFreq;
    };

    int arrayValMaxFreq = maxFrequencyOfArrayVal(v);

    int l = 0, otherValMaxFreq = 0;

    for(int r = 0; r < n; r++) {
        while((long long)v[r] > (long long)v[l] + 2LL * k)
            l++;

        otherValMaxFreq = max(otherValMaxFreq, r - l + 1);

        if(otherValMaxFreq >= numOperations) {
            otherValMaxFreq = numOperations;
            break;
        }
    }

    cout << max(arrayValMaxFreq, otherValMaxFreq) << '\n';
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