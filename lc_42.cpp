#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string n1 = "", n2 = "";
    cin >> n1 >> n2;

    if(n1 == "0" || n2 == "0") {cout << "0\n"; return;}

    vector<int> res(n1.size() + n2.size(), 0);

    for(int i = n1.size() - 1; i >= 0; i--) {
        for(int j = n2.size() - 1; j >= 0; j--) {
            res[i + j + 1] += (n1[i] - '0')*(n2[j]-'0');
            res[i + j] += res[i + j + 1] / 10;
            res[i + j + 1] %= 10;
        }
    }

    int i = 0;
    string ans = "";
    while(res[i] == 0) i++;
    while(i < res.size()) ans += to_string(res[i++]);

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