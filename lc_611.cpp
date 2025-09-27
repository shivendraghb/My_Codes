#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    int cnt = 0;
    for(int i = v.size() - 1; i >= 2; i--) {
        int l = 0, r = i - 1;
        while(l < r) {
            if(v[l] + v[r] > v[i]) {
                cnt += r - l;
                r--;
            }
            else l++;
        }
    }

    cout << cnt << '\n';
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
