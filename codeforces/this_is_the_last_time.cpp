#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    /*
        casinos[i][0] = l
        casinos[i][1] = r
        casinos[i][2] = real
    */

   vector<vector<int>> casinos(n, vector<int>(3));
   for(int i = 0; i < n; i++)
   cin >> casinos[i][0] >> casinos[i][1] >> casinos[i][2];

    //if(k == 0) cout << "0" << '\n';


    sort(casinos.begin(), casinos.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });

    int max_coins = 0, coins = k;

    for(int i = 0; i < n; i++) {
       if(coins >= casinos[i][0] && coins <= casinos[i][1])
         coins = casinos[i][2];

       max_coins = max(coins, max_coins);
    }
    cout << max_coins << '\n';
 }

int32_t main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
