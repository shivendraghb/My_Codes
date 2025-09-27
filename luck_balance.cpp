#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> contests(n, vector<int>(2));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 2; j++)
            cin >> contests[i][j];

    /*
        if loses then luck increases by L[i]
        if wins then luck decreases by L[i]
    */i

    sort(contests.begin(), contests.end(), [](vector<int> a, vector<int> b) {
        return a[0] > b[0];
    });

    /*
        If you must win some important contests (because you can only lose k of them),
        you’d rather win the ones with the smallest luck loss.

        Conversely, you’d want to lose the important contests
        with the largest luck value to maximize gain.

        Sorting ensures you consider high-luck contests first.
    */

    int r = 0, imp = 0;

    for(int i = 0; i < contests.size(); i++) {
        if(imp < k || contests[i][1] == 0)
            r += contests[i][0];
        else
            r -= contests[i][0];
        if(contests[i][1] == 1)
            imp++;
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
