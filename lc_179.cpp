#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i< n; i++)
        cin >> a[i];

    vector<string> s;
    for(int x : a)
        s.push_back(to_string(x));

    sort(s.begin(), s.end(), [](const string &a, const string &b) {
        return (b + a) < (a + b);
    });

    if(s[0] == "0") {
        cout << "0";
        return;
    }

    string l;
    for(string t : s)
        l += t;

    cout << l << '\n';
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
