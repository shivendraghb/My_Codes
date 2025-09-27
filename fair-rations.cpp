#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    //greedily increase cnt;
    //check for odd and give 1 bread to next
    //cnt += 2
    //starting from 0 so should check for next person
    //if he is odd i give a bread to next person
    //irrespective of their bread count
    //no need to give the current person a bread
    //just include their cnt as well

    int cnt = 0;
    string r = "NO";
    for(int i = 0; i < n - 1; i++) {
        if(v[i] % 2 == 1) {
            v[i + 1]++;
            cnt += 2;
        }
    }

    //if(B[n - 1] % 2 == 0) return to_string(cnt);
    //return "NO";
    if(v[n - 1] % 2 == 0) {cout << cnt << '\n';}
    else cout << "NO" << '\n';
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
