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

    vector<vector<int>> temp;
    for(int i = 0; i < v.size(); i++) {
        int d = v[i][0] + v[i][1];
        temp.push_back({d, i + 1});
    }

    sort(temp.begin(), temp.end());
    
    vector<int> res;

    for(auto ele : temp)
        res.push_back(ele[1]);

    for(auto const i : res)
        cout << i << " ";
    cout << '\n';
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