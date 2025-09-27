#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int nr, dr;
    cin >> nr >> dr;

    string ans;
    if(nr == 0) {cout << "0\n"; return;}

    if((nr < 0) ^ (dr < 0))
        ans += "-";

    ll n = llabs((ll)nr);
    ll d = llabs((ll)dr);

    ans += to_string(n / d);

    ll rem = n % d;
    if(rem == 0) {cout << ans << '\n'; return;}

    ans += ".";
    unordered_map<ll, int> mp;

    while(rem != 0) {
        if(mp.count(rem)) {
            ans.insert(mp[rem], "(");
            ans += ")";
            break;
        }
        mp[rem] = ans.size();
        rem *= 10;
        ans += to_string(rem / d);
        rem %= d;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
