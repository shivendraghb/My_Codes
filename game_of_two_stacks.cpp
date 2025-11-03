#include<bits/stdc++.h>
using namespace std;

#define int long long

int f(vector<int>& a, vector<int>& b, int x) {
    int s = 0, i = 0, j = 0, n = a.size(), m = b.size(), ans = 0;
    while(i < n && s + a[i] <= x) s += a[i++];
    ans = i;
    while(j < m) {
        s += b[j++];
        while(s > x && i > 0) s -= a[--i];
        if(s > x) break;
        ans = max(ans, i + j);
    }

    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, m, x;
        cin >> n >> m >> x;
        vector<int> a(n), b(m);
        for(auto &i : a) cin >> i;
        for(auto &i : b) cin >> i;
        cout << f(a, b, x) << '\n';
    }

    return 0;
}