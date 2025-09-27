#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(2));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 2; j++)
            cin >> v[i][j];

    sort(v.begin(), v.end(), [](const vector<int>& p, const vector<int>& q) {
        return (p[0] == q[0]) ? p[1] < q[1] : p[0] > q[0];
    });

    int a = 0;
    for(int i = 0; i < v.size() - 1; i++) {
        int y = INT_MAX;
        for(int j = i + 1; j < v.size(); j++) {
            if(v[j][1] >= v[i][1] && y > v[j][1]) {
                a++;
                y = v[j][1];
            }
        }
    }

    cout << a << '\n';
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
