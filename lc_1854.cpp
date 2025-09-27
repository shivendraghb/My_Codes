#include<bits/stdc++.h>
using namespace std;

#define int long long

int maximumPopulation(vector<vector<int>>& logs) {
    int years[2051] = {0};
    for(auto& log : logs) {
        years[log[0]]++;
        years[log[1]]--;
    }

    int mp = 0, my = 1950, cp = 0;
    for(int year = 1950; year < 2051; year++) {
        cp += years[year];
        if(cp > mp) {
            mp = cp;
            my = year;
        }
    }

    return my;
}
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> logs(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> logs[i][0] >> logs[i][1];
    }
    cout << maximumPopulation(logs) << '\n';
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

