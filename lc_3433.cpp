#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    cin.ignore();

    vector<vector<string>> ev(m);
    for(int i = 0; i < m; i++) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        
        string t1, t2;
        ss >> t1 >> t2;
        
        ev[i] = {t1, t2};

        string rest;
        getline(ss, rest);
        if(!rest.empty() && rest[0] == ' ')
            rest = rest.substr(1);

        ev[i].push_back(rest);
    }

    sort(ev.begin(), ev.end(), [](auto &a, auto &b) {
        int ta = stoi(a[1]), tb = stoi(b[1]);
        if (ta != tb) return ta < tb;
        return a[0] == "OFFLINE";
    });

    vector<int> res(n, 0), online(n, 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int allcnt = 0;

    for (auto &e : ev) {
        int t = stoi(e[1]);

        while (!pq.empty() && pq.top().first <= t) {
            online[pq.top().second] = 1;
            pq.pop();
        }
        if (e[0] == "OFFLINE") {
            int u = stoi(e[2]);
            online[u] = 0;
            pq.push({t + 60, u});
        } else {
            string &msg = e[2];
            if (msg == "ALL")
                allcnt++;
            else if (msg == "HERE") {
                for (int u = 0; u < n; u++)
                    if (online[u]) res[u]++;
            } else {
                stringstream ss(msg);
                string tok;
                while (ss >> tok) {
                    int u = stoi(tok.substr(2));
                    res[u]++;
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
        res[i] += allcnt;

    for(int i : res)
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