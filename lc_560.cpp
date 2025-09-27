#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    unordered_map<int, int> mp;

    mp[0] = 1;

    int t = 0, cnt = 0;
    for(int i : v) {
        t += i;

        if(mp.count(t - k))
            cnt += mp[t - k];

        mp[t]++;
    }

    cout << cnt << '\n';

    //brute force

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        int sum = v[i];

        if(sum == k)
            ans++;

        for(int j = i + 1; j < n; j++)
        {
            sum += v[j];

            if(sum == k)
                ans++;
        }

    }

    // cout << ans << '\n';
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
