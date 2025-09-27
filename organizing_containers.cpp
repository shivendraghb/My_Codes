#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int m;
    cin >> m;

    vector<vector<int>> c(m, vector<int>(m));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            cin >> c[i][j];

    vector<int> c_t(m, 0);
    vector<int> b_t(m, 0);

    /*
        Each container has a fixed total capacity(sum of all its balls)
        can't change this total only  redistribute

        Each ball type has a fixed total count across all containers
        can't change this either

        To be possible set of container capacities must match the set
        of type of totals

        When you see “two arrays, check if they contain the same numbers
        regardless of order” → that’s the classic “sort then compare” trick.

        “I don’t care which container matches which type, only that all totals match.”
        “So let’s sort both totals, then just compare linearly.”

        Sorting forces both arrays into canonical order: the smallest value first, the largest last.
        So if both arrays are identical multisets, after sorting they must be literally the same array.
    */

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            c_t[i] += c[i][j];
            b_t[j] += c[i][j];
        }
    }

    sort(c_t.begin(), c_t.end());
    sort(b_t.begin(), b_t.end());

    bool flag = true;

    for(int i = 0; i < c_t.size(); i++) {
        if(c_t[i] != b_t[i]) {
            flag = false;
            break;
        }
    }

    if(flag){
        cout << "Possible" << '\n';
    } else if(!flag)
        cout << "Impossible" << '\n';
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
