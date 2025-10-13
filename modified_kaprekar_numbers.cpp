#include<bits/stdc++.h>
using namespace std;

#define int long long

void kaprekarnumbers(int p, int q) {
    vector<int> res;

    for(int i = p; i <= q; i++) {
        long long sq = 1LL * i * i;
        string s = to_string(sq);
        int d = to_string(i).size();

        string rp = s.substr(s.size() > d ? s.size() - d : 0);
        string lp = s.substr(0, s.size() - d);

        long long left = (lp.empty() ? 0 : stoll(lp)); 
        long long right = (rp.empty() ? 0 : stoll(rp)); 

        if(left + right == i)
            res.push_back(i);
    }
    
    if(res.empty()) cout << "INVALID RANGE\n";
    else {
        for(int i = 0; i < (int)res.size(); i++)
            cout << res[i] << (i + 1 == res.size() ? '\n' : ' ');
    }
}

void solve() {
    int p, q;
    cin >> p >> q;

    kaprekarnumbers(p, q);
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