#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> r;

    for(int i = 0; i < n; i++) {
        r.push_back(v[i]);
        while(r.size() > 1) {
            int a = r.back();
            int b = r[r.size() - 2];
            int g = gcd(a, b);
            if(g > 1) {
                r.pop_back();
                r.pop_back();
                long long lcm = (long long) a / g * b;
                r.push_back((int)lcm);
            } else
                break;
        }
    }

    for(int i : r)
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
