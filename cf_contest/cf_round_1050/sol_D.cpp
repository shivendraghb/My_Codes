#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while(T--) {
        int n;
        cin >> n;
        vector<int64> odds;
        int64 sumEvens = 0;
        for(int i=0;i<n;i++){
            int64 a; cin >> a;
            if(a % 2 == 0) sumEvens += a;
            else odds.push_back(a);
        }
        if(odds.empty()) {
            cout << 0 << '\n';
            continue;
        }
        sort(odds.begin(), odds.end(), greater<int64>()); // descending
        int take = (odds.size() + 1) / 2; // ceil(k/2)
        int64 sumOdds = 0;
        for(int i=0;i<take;i++) sumOdds += odds[i];
        cout << (sumEvens + sumOdds) << '\n';
    }
    return 0;
}
