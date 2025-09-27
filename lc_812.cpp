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

    double maxArea = 0;
    for(int i = 0; i < n - 2; i++) {
        const int a0 = v[i][0], a1 = v[i][1];
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {
                double area = 0.5*((v[j][0]-a0)*(v[k][1]-a1)-(v[j][1]-a1)*(v[k][0]-a0));
                if(area < 0) area = -area;
                maxArea = max(maxArea, area);
            }
        }
    }

    cout << setprecision(5) << maxArea << '\n';
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
