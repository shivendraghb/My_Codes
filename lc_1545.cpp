#include<bits/stdc++.h>
using namespace std;

#define int long long

char solve(int n, int k) {
    if (n == 1) return '0';

    int len = (1 << n) - 1;
    int mid = (len + 1) / 2;

    if (k == mid) return '1';

    if (k < mid) return solve(n - 1, k);

    char bit = solve(n - 1, len - k + 1);
    return (bit == '0') ? '1' : '0';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << '\n';
    }

    return 0;
}