#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int m, n;
    cin >> m >> n;
    int diag[10];

    vector<vector<int>> v(m, vector<int>(n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> v[i][j];

    // const int n = v.size();
    cout << '\n';

    for(int d = n - 2; d > 0; d--) {
        for(int i = 0; i < n - d; i++)
            diag[i] = v[i][i + d];
        sort(diag, diag + (n - d));
        for(int i = 0; i < n - d; i++)
            v[i][i + d] = diag[i];
    }
    for(int d = 0; d < n - 1; d++) {
        for(int j = 0; j < n - d; j++)
            diag[j] = v[j + d][j];
        sort(diag, diag + (n - d), greater<int>());
        for(int j = 0; j < n - d; j++)
            v[j + d][j] = diag[j];
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cout << v[i][j] << " ";
        cout << '\n';
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
