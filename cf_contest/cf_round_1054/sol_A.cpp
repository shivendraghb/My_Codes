#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int neg = 0, zero = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == -1) neg++;
            else if (a[i] == 0) zero++;
        }
        int ans = zero + (neg % 2) * 2;
        cout << ans << "\n";
    }
}