#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    char target;
    cin >> target;

    vector<char> l(n);
    for(int i = 0; i < n; i++)
        cin >> l[i];

    int low = 0, high = l.size() - 1;
    int pos = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(l[mid] > target) {
            pos = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    if(pos == -1) {
        cout << l[0] << '\n';
        return;
    }
    else {
        cout << l[pos] << '\n';
        return;
    }
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
