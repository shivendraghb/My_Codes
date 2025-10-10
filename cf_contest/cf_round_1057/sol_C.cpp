#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while(t--) {
        int n; cin >> n;
        vector<ll> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a.begin(), a.end());
        map<ll,int> cnt;
        for(auto v: a) cnt[v]++;

        map<ll,int> sel = cnt;
        vector<ll> oddVals;
        for(auto &p: sel) if(p.second % 2 == 1) oddVals.push_back(p.first);
        
        if(!oddVals.empty()) {
            sort(oddVals.begin(), oddVals.end());
            int removeCount = (int)oddVals.size() - 1;
            for(int i=0;i<removeCount;i++) {
                ll v = oddVals[i];
                sel[v]--; 
                if(sel[v] == 0) sel.erase(v);
            }
        }

        multiset<ll> S;
        ll total = 0;
        for(auto &p: sel) {
            for(int i=0;i<p.second;i++) {
                S.insert(p.first);
                total += p.first;
            }
        }

        set<ll> oddSet;
        for(auto &p: sel) if(p.second % 2 == 1) oddSet.insert(p.first);

        auto remove_one = [&](ll v){
            auto it = S.find(v);
            if(it != S.end()) {
                S.erase(it);
                total -= v;
            }
            auto itmap = sel.find(v);
            if(itmap != sel.end()) {
                itmap->second--;
                if(itmap->second == 0) sel.erase(itmap);
            }
        };

        if((int)S.size() < 3) {
            cout << 0 << '\n';
            continue;
        }

        while(true) {
            if((int)S.size() < 3) break;
            ll mx = *S.rbegin();
            if(2 * mx < total) break;
            remove_one(mx);
            oddSet.clear();
            for(auto &p: sel) if(p.second % 2 == 1) oddSet.insert(p.first);

            while((int)oddSet.size() > 1 && (int)S.size() >= 3) {
                ll vv = *oddSet.begin();
                remove_one(vv);
                oddSet.clear();
                for(auto &p: sel) if(p.second % 2 == 1) oddSet.insert(p.first);
            }
        }

        if((int)S.size() >= 3) {
            ll mx = *S.rbegin();
            if(2 * mx < total) cout << total << '\n';
            else cout << 0 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}
