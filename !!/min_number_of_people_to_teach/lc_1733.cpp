#include<bits/stdc++.h>
using namespace std;

//#define int long long

void solve() {
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<vector<int>> lang(m);
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        for(int j = 0; j < x; j++) {
            int y;
            cin >> y;
            lang[i].push_back(y);
        }
    }

    int p;
    cin >> p;

    vector<vector<int>> friends(p, vector<int>(2));
    for(int i = 0; i < p; i++)
        for(int j = 0; j < 2; j++)
            cin >> friends[i][j];

    vector<unordered_set<int>> langSets(m);
    for(int i = 0; i < m; i++)
        for(int l : lang[i])
            langSets[i].insert(l);

    int ans = INT_MAX;

    for(int L = 1; L <= n; L++) {
        unordered_set<int> toTeach;

        for(auto& f : friends) {
            int u = f[0] - 1;
            int v = f[1] - 1;

            bool canTalk = false;
            for(int l : langSets[u]) {
                if(langSets[v].count(l)) {
                    canTalk = true;
                    break;
                }
            }
            if(canTalk) continue;

            if(!langSets[u].count(L)) toTeach.insert(u);
            if(!langSets[v].count(L)) toTeach.insert(v);
        }

        ans = min(ans, (int)toTeach.size());
    }

    cout << ans << '\n';

    // vector<unordered_set<int>> langSets(m);
    // for(int i = 0; i < m; i++)
    //     for(int l : lang[i])
    //         langSets[i].insert(l);

    // unordered_set<int> badUsers;
    // for(auto& f : friends) {
    //     int u = f[0] - 1;
    //     int v = f[1] - 1;

    //     bool canTalk = false;
    //     for(int l : langSets[u]) {
    //         if(langSets[v].count(l)) {
    //             canTalk = true;
    //             break;
    //         }
    //     }
    //     if(!canTalk) {
    //         badUsers.insert(u);
    //         badUsers.insert(v);
    //     }
    // }

    // int ans = INT_MAX;
    // for(int L = 1; L <= n; L++) {
    //     int cnt = 0;
    //     for(int u : badUsers)
    //         if(!langSets[u].count(L))
    //             cnt++;

    //     ans = min(ans, cnt);
    // }

    // cout << ans << '\n';
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
