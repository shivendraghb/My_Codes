#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    // if(!(cin >> t)) return 0;
    while(t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        if((n - b) % 2 != 0) {
            cout << "NO\n";
            continue;
        }
        if(a <= b) {
            cout << "YES\n";
            continue;
        }
        if((n - a) % 2 == 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}

