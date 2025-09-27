#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    if(n < 4) {
        cout << "false" << '\n';
        return;
    }

    vector<int> dis(n);
    for(int i = 0; i < n; i++)
        cin >> dis[i];

    /*
        1st <--> 4th
        ------------------------------------------
        The 4th line(i-3) should be longer than
        2nd line(i-1)
        The 3rd line(i-2) should be shorter
        than 1st line(i)
        ------------------------------------------

        1st <--> 6th
        ------------------------------------------
        3rd must be longer than 1st
        4th must be longer than 2nd

        The sum of 2nd line(i-1) and 6th line(i-5)
        must be greater than the 4th line(i-3)

        The 1st line(i) and the 5th line(i-4)
        must be greater than the 3rd line(i-2)
        ------------------------------------------
    */
    for(int i = 3; i < n; i++) {
        if(dis[i] >= dis[i - 2] && dis[i - 1] >= dis[i - 3]) {
            cout << "true" << '\n';
            return;
        }
        if(i >= 5) {
              //
            if(dis[i - 1] <= dist[i - 3] && dis[i - 2] >= dis[i - 4] && dis[i - 5] >= dis[i - 3] - dis[i - 1] && dis[i] >= dis[i - 2] - dis[i - 4]) {
                cout << "true" << '\n';
                return;
            }
        }
    }

    cout << "false" << '\n';
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
