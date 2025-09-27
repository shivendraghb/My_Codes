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


    //return area of the rectangle having the longest diagonal
    //if there are multiple rectangles with the longest diagonal
    //return the area of the rectangle having the maimum area

    int maxd = 0, maxa = 0;

    for(int i = 0; i < n; i++) {
        int l = v[i][0];
        int b = v[i][1];

        int d = l * l + b * b;
        int a = l * b;
        if(d > maxd) {
            maxd = d;
            maxa = a;
        }
        else if(d == maxd) {
            maxa = max(maxa, a);
        }
    }

    cout << maxa << '\n';
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
