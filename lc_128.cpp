#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    unordered_set<int> s(nums.begin(), nums.end());
    int a = 0;

    for(int i : s){
        if(!s.count(i - 1)){
            int l = 1, curr = i;
            while(s.count(curr + 1)){
                l++;
                curr++;
            }
            a = max(a, l);
        }
    }

    cout << a << '\n';
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
