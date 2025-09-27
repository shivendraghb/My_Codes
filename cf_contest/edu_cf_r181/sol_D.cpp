#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod = 10e22 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v;

    for(int i = 0; i < m ; i++){
        v.push_back(i);
    }

    int s = 0;

    for(int i = 0; i < m; i++){
        s += v[i];
    }

    vector<int> cp;
    for(int i = 0; i < m - 1; i++){
        cp.push_back(s - v[i]);
    }


}

int32_t main(){
    int t;
    cin >> t;

    while(t--) {

    }
}
