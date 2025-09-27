#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while(t--) {
        long long n,m,x,y;
        cin >> n >> m >> x >> y;
        for(int i=0;i<n;i++){ long long tmp; cin >> tmp; } // read a[]
        for(int j=0;j<m;j++){ long long tmp; cin >> tmp; } // read b[]
        cout << (n + m) << "\n";
    }
    return 0;
}