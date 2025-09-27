#include<bits/stdc++.h>
using namespace std;

#define int long long

string countDigits(int n) {
    string s = to_string(n);
    sort(s.begin(), s.end());
    return s;
}

bool reorderedPowerof2(int n) {
    string target = countDigits(n);
    for(int i = 0; i < 31; i++) {
        if(countDigits(1 << i) == target)
            return true;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;

    if(reorderedPowerof2(n))
        cout << "true" << '\n';
    else
        cout << "false" << '\n';
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
