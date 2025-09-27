#include <bits/stdc++.h>
using namespace std;

long long countAtMost(const vector<int>& a, int X, int L) {
    if (X == 0 || L == 0) return 0;
    int n = a.size();
    unordered_map<int,int> freq;
    int distinct = 0;
    int left = 0;
    long long res = 0;
    for (int right = 0; right < n; right++) {
        if (++freq[a[right]] == 1) distinct++;
        while (distinct > X) {
            if (--freq[a[left]] == 0) distinct--;
            left++;
        }
        int minLeft = max(left, right - L + 1);
        res += (right - minLeft + 1);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k, l, r;
        cin >> n >> k >> l >> r;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long ans = (
            countAtMost(a, k, r) - countAtMost(a, k, l-1)
          - countAtMost(a, k-1, r) + countAtMost(a, k-1, l-1)
        );
        cout << ans << "\n";
    }
}
