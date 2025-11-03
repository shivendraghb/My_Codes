#include<bits/stdc++.h>
using namespace std;

#define int long long

string gridSearch(vector<string> G, vector<string> P) {
    int R = G.size();
    int C = G[0].size();
    int r = P.size();
    int c = P[0].size();

    for(int i = 0; i <= R - r; i++) {
        size_t pos = G[i].find(P[0]);
        while(pos != string::npos) {
            bool match = true;
            for(int k = 1; k < r; k++) {
                if(G[i + k].substr(pos, c) != P[k]) {
                    match = false;
                    break;
                }
            }
            if(match) return "YES";
            pos = G[i].find(P[0], pos + 1);
        }
    }

    return "NO";
}

int32_t main() {
    int t;
    cin >> t;

    while(t--) {
        int R, C;
        cin >> R >> C;
        vector<string> G(R);
        for(int i = 0; i < R; i++) cin >> G[i];

        int r, c;
        cin >> r >> c;
        vector<string> P(r);
        for(int i = 0; i < r; i++) cin >> P[i];

        cout << gridSearch(G, P) << '\n';
    }

    return 0;
}