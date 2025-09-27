#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int c = 0;
    // for(int i = 0; i < n; i++) {
    //     if(a[i] == 0) {
    //         c++;
    //         int j = i + 1;
    //         while(j < n) {
    //             if(a[j] == 0) {
    //                 c++;
    //                 j++;
    //             }
    //             else break;
    //         }
    //     }
    // } n^2
    int streak = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            streak++;
            c += streak;
        }
        else streak = 0;
    }

    cout << c << '\n';
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
