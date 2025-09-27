#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    if(k < 2) cout << "-1" << '\n';

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    unordered_map<int, int> candidates;

    for(int n : nums) {
        if(candidates.count(n))
            candidates[n]++;
        else if(candidates.size() < k - 1)
            candidates[n] = 1;
        else {
            // cancel votes
            vector<int> toErase;
            for(auto &p : candidates) {
                p.second--;
                if(p.second == 0)
                    toErase.push_back(p.first);
            }
            for(int key : toErase)
                candidates.erase(key);
        }
    }
    //verify
    unordered_map<int, int> freq;
    for(int n : nums)
        if(candidates.count(n))
            freq[n]++;

    vector<int> res;
    for(auto &p : freq) {
        if(p.second > nums.size() / k)
            res.push_back(p.first);
    }

    for(int i : res)
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
