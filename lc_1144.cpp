#include <bits/stdc++.h>
using namespace std;

// #define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int even_steps = 0, odd_steps = 0;

    for(int i = 0; i < n; i++) {
        int left = (i > 0 ? a[i - 1] : INT_MAX);
        int right = (i + 1 < n ? a[i + 1] : INT_MAX);
        int minneighbor = min(left, right);

        if(i % 2 == 0)
            odd_steps += max(0, a[i] - minneighbor + 1);
        else
            even_steps += max(0, a[i] - minneighbor + 1);
    }

    cout << min(even_steps, odd_steps) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
