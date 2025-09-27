#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> num1(n), num2(n), num3(n), num4(n);
    for (int i = 0; i < n; i++) cin >> num1[i];
    for (int i = 0; i < n; i++) cin >> num2[i];
    for (int i = 0; i < n; i++) cin >> num3[i];
    for (int i = 0; i < n; i++) cin >> num4[i];

    unordered_map<int, int> sum;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum[num1[i] + num2[j]]++;
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int target = -(num3[i] + num4[j]);
            if (sum.count(target)) {
                res += sum[target];
            }
        }
    }
    cout << res << '\n';
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
