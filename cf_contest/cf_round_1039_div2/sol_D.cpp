#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n);
        for(int i = 0; i < n; i++){
            cin >> p[i];
        }
        ll total = ll(n) * (n + 1) / 2;
        ll extra = 0;
        for(int i = 0; i + 1 < n; i++){
            if(p[i] > p[i + 1]){
                extra += ll(i + 1) * ll(n - (i + 1));
                // i+1 is position 1‑based; n‑(i+1) is how many r‑choices
            }
        }
        cout << (total + extra) << "\n";
    }
    return 0;
}
