#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    priority_queue<int> pq(s.begin(), s.end());

    while (pq.size() > 1) {
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();

        if (x != y) pq.push(x - y);
    }

    cout << (pq.empty() ? 0 : pq.top()) << '\n';
}

int32_t main() {
    int t;
    cin >> t;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(t--) {
        solve();
    }

    return 0;
}