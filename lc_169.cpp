#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >>v[i];

    // unordered_map<int, int> mp;
    // for(int i : v)
    //     mp[i]++;

    // for(const auto& pair : mp) {
    //     if(pair.second > n / 2)
    //         return pair.first;
    // }

    // return 0;

    //Boyer Moore Voting Algorithm
    int candidate = -1, count = 0;
    for(int num : v) {
        if(count == 0) {
            candidate = num;
            count = 1;
        } else if(num == candidate) {
            count++;
        } else {
            count--;
        }
    }

    count = 0;
    for(int num : v) {
        if(num == candidate) count++;
    }
    if(count > n / 2)
        cout << candidate << '\n';
    else
        cout << 0 << '\n';
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
