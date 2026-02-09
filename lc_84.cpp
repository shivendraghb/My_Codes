#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    int ma = 0;

    for (int i = 0; i < n; i++) {
        int mh = h[i];
        for (int j = i; j < n; j++) {
            mh = min(mh, h[j]);
            int w = j - i + 1;
            ma = max(ma, mh * w);
        }
    }

    int maxa = 0;
    
    for (int i = 0; i < n; i++) {
        int l = i, r = i;
        int height = h[i];

        while (l > 0 && h[l - 1] > h[i])
            l--;
        while (r < n - 1 && h[r + 1] > h[i])
            r++;
        
        int width = r - l + 1;
        int a = height * width;
        maxa = max(maxa, a);
    }

    cout << ma << '\n';
    cout << maxa << '\n';
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
