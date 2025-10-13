#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<string> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    // vector<unordered_map<char, int>> mp(n);
    
    // for(int i = 0; i < n; i++)
    //     for(char ch : v[i])
    //         mp[i][ch]++;

    // vector<string> ans;
    // ans.push_back(v[0]);

    // for(int i = 1; i < n; i++)
    //     if(mp[i] != mp[i - 1])
    //         ans.push_back(v[i]);

    vector<string> ans;
    ans.push_back(v[0]);

    for(int i = 1; i < n; i++) {
        string a = v[i], b = ans.back();
        sort(a.begin(), a.end()), sort(b.begin(), b.end());
        if(a != b) ans.push_back(v[i]);
    }

    for(string c : ans)
        cout << c << " ";
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