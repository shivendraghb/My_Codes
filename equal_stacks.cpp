#include<bits/stdc++.h>
using namespace std;

// #define int long long

void solve () {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<int> v1(n1);
    vector<int> v2(n2);
    vector<int> v3(n3);
    
    for(int i = 0; i < n1; i++)
        cin >> v1[i];

    for(int i = 0; i < n2; i++)
        cin >> v2[i];

    for(int i = 0; i < n3; i++)
        cin >> v3[i];

    auto sum = [&](const vector<int>& v) {
        return accumulate(v.begin(), v.end(), 0);
    };

    int s1 = sum(v1), s2 = sum(v2), s3 = sum(v3);
    int i1 = 0, i2 = 0, i3 = 0;

    while(true) {
        if(s1 == s2 && s2 == s3) { cout << s1; return; }

        int mx = max({s1, s2, s3});
        if(s1 == mx) s1 -= v1[i1++];
        else if(s2 == mx) s2 -= v2[i2++];
        else s3 -= v3[i3++];
    }
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