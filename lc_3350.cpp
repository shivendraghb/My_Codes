#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    // int suff = 1, pre = 0, ans = 0;

    // for(int i = 1; i < v.size(); i++) {
    //     if(v[i] > v[i - 1])
    //         suff++;
    //     else {
    //         pre = suff;
    //         suff = 1;
    //     }

    //     ans = max({ans, suff / 2, min(suff, pre)});
    // }

    // cout << ans << '\n';

    
        vector<int> pre(n + 1), suff(n + 1);

        for(int i = 1; i <= n; i++) {
            if(i > 1 && v[i - 2] < v[i -1])
                pre[i] = pre[i - 1] + 1;
            else
                pre[i] = 1;
        }
        for(int i = n; i > 0; i--) {
            if(i < n && v[i - 1] < v[i])
                suff[i] = suff[i + 1] + 1;
            else
                suff[i] = 1;
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans = max(ans, min(pre[i - 1], suff[i]));
        }

        cout << ans << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}