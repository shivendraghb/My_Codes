#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, res = 0;
    cin >> n;

    vector<vector<int>> f(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> f[i][j];
        }
    }

    for(int i = 0; i < n; i++)
        res += f[i][i];

    for(int i = 0; i < 2; i++) {
        if(i == 1) {
            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < n; j++) {
                    swap(f[i][j], f[j][i]);
                }
            }
        }

        vector<int> prev(n, -1), curr(n, -1);
        prev[n - 1] = f[0][n - 1];

        for(int row = 1; row < n; row++) {
            fill(curr.begin(), curr.end(), -1);
            for(int i = 0; i < n; i++) {
                if(prev[i] < 0) continue;

                if(i > 0)
                    curr[i - 1] = max(curr[i - 1], prev[i] + f[row][i - 1]);

                if(i < n - 1)
                    curr[i + 1] = max(curr[i + 1], prev[i] + f[row][i + 1]);

                curr[i] = max(curr[i], prev[i] + f[row][i]);
            }
            swap(prev, curr);
        }
        res += prev[n - 1];
    }

    cout << r << '\n';
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
