#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int ac, dr;
    cin >> ac >> dr;
 
    int n;
    cin >> n;
 
    vector<int> a(n), d(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> d[i];
 
    vector<int> t(n);
    const int MAXT = 2*1e6 + 5;
    vector<int> cnt(MAXT, 0);
 
    for(int i = 0; i < n; i++){
        t[i] = max(a[i]-ac,0) + max(d[i]-dr,0);
        cnt[t[i]]++;
    }
 
    auto simulate = [&](int start_p) -> int {
        int p = start_p;
        while(p < MAXT && cnt[p] > 0){
            p += cnt[p];
        }
        return p;
    };
 
    int m;
    cin >> m;
    int p = 0;
    for(int i = 0; i < m; i++){
        int k, na, nd;
        cin >> k >> na >> nd;
        k--; // 0-indexed
 
        int old_t = t[k];
        cnt[old_t]--;
 
        t[k] = max(na-ac,0) + max(nd-dr,0);
        cnt[t[k]]++;
 
        int start = min(p, min(old_t, t[k]));
        p = simulate(start);
        cout << p << "\n";
    }
 
    return 0;
}