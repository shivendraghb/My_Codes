#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m, h;
    cin >> n >> m >> h;

    /*
       n : num of cars
       m : the number of power outlets
       h : number of hours
       Ai : energy capacity of i-th car
       Bj : energy provided by j-th outlet
    */

    vector<int> N(n);
    for(int i = 0; i < n; i++)
        cin >> N[i];

    vector<int> M(m);
    for(int i = 0; i < m; i++)
        cin >> M[i];

    sort(N.begin(), N.end(), greater<int>());
    sort(M.begin(), M.end(), greater<int>());

    int tp = 0;

    for(int i = 0; i < min(n, m); i++)
        tp += min(N[i], M[i] * h);

    // int i = 0;
    // while(i < min(n, m)){
    //     if(M[i] * h < N[i]) {
    //         tp += M[i] * h;
    //         i++;
    //     }
    //     else {
    //         tp += N[i];
    //         i++;
    //     }
    // }

    cout << tp << '\n';
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
