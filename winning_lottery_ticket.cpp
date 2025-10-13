#include<bits/stdc++.h>
using namespace std;

#define int long long

int winninglotterytickets(vector<string>& v) {
    const int FULL_MASK = (1 << 10) - 1;
    vector<int> freq(1 << 10, 0);
    
    for(auto &s : v) {
        int mask = 0;
        for(char c : s) mask |= (1 << (c - '0'));
        freq[mask]++;
    }

    int ans = 0;
    for(int i = 0; i < (1 << 10); i++) {
        for(int j = i; j < (1 << 10); j++) {
            if((i | j) == FULL_MASK) {
                if(i == j)
                    ans += freq[i] * (freq[i] - 1) / 2;
                else
                    ans += freq[i] * freq[j];
            }
        }
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;

    vector<string> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    cout << winninglotterytickets(v) << '\n';
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