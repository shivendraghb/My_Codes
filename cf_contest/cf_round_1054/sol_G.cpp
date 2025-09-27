#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    while(t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n+1);
        unordered_map<int, vector<int>> pos; // positions of each number
        for(int i=1;i<=n;i++){
            cin >> a[i];
            pos[a[i]].push_back(i);
        }

        while(q--){
            int l, r;
            cin >> l >> r;
            int len = r-l+1;
            int T = len/3;
            set<int> res;
            set<int> checked;

            for(int it=0; it<20 && res.size()<2; it++){
                int idx = uniform_int_distribution<int>(l, r)(rng);
                int val = a[idx];
                if(checked.count(val)) continue;
                checked.insert(val);

                auto &v = pos[val];
                int cnt = upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
                if(cnt > T) res.insert(val);
            }

            if(res.empty()) cout << -1 << "\n";
            else{
                for(auto it=res.begin(); it!=res.end(); it++){
                    if(it!=res.begin()) cout << " ";
                    cout << *it;
                }
                cout << "\n";
            }
        }
    }
}
