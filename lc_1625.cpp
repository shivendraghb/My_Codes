#include<bits/stdc++.h>
using namespace std;

#define int long long

auto addOp = [](const string &t, int a, int b) {
    string res = t;
    int n = t.size();
    for(int i = 1; i < n; i += 2)
        res[i] = (res[i] - '0' + a) % 10 + '0';

    return res;
};

auto rotOp = [](const string &t, int a, int b) {
    int n = t.size();
    return t.substr(n - b) + t.substr(0, n - b);
};

void solve() {
    string s;
    int a, b;
    cin >> s >> a >> b;

    int n = s.size();

    unordered_set<string> seen;
    queue<string> q;
    q.push(s);
    seen.insert(s);
    string ans = s;

    // auto addOp = [&](const string &t) {
    //     string res = t;
    //     for(int i = 1; i < n; i += 2)
    //         res[i] = (res[i] - '0' + a) % 10 + '0';

    //     return res;
    // };

    // auto rotOp = [&](const string &t) {
    //     return t.substr(n - b) + t.substr(0, n - b);
    // };

    while(!q.empty()) {
        string cur = q.front();
        q.pop();
        ans = min(ans, cur);

        // string added = addOp(cur);
        string added = addOp(cur, a, b);
        if(!seen.count(added)) {
            seen.insert(added);
            q.push(added);
        }

        // string rotated = rotOp(cur);
        string rotated = rotOp(cur, a, b);
        if(!seen.count(rotated)) {
            seen.insert(rotated);
            q.push(rotated);
        }
    }

    cout << ans << '\n';
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