#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    cin >> s;
    
    int n = s.size();
    int startWith0 = 0;
    int startWith1 = 0;
    
    for(int i = 0; i < n; i++) {
        char expected0 = (i % 2 == 0) ? '0' : '1';
        char expected1 = (i % 2 == 0) ? '1' : '0';
        
        if(s[i] != expected0) startWith0++;
        if(s[i] != expected1) startWith1++;
    }
    
    cout << min(startWith0, startWith1) << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}