#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    int temp = n;
    int canget = 0;
    while(n / m > 0) {
        canget += n / m;
        int rem = 0; 
        rem = n % m;
        n /= m;
        n += rem;
    }

    cout << temp + canget << '\n';
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