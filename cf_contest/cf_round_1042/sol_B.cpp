#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while(t--) {
        int n; cin >> n;
        vector<long long> a(n+1,0);   // 1-based for a
        vector<long long> s(n+1,0);   // prefix sums, s[0]=0
        vector<long long> prefMax(n+1,LLONG_MIN); // prefMax[i] = max(s[0..i])
        s[0] = 0;
        prefMax[0] = 0;
        for(int i=1;i<=n;i++){
            if(i % 2 == 1){ // odd index -> put negative (try -1)
                // we need a[i] > max_{t=0..i-2}( s[t] - s[i-1] )
                long long max_before = (i-2 >= 0 ? prefMax[i-2] : LLONG_MIN);
                long long need = max_before - s[i-1]; // a[i] > need
                long long ai = -1;
                if( !(ai > need) ) {
                    // pick minimal integer > need
                    ai = need + 1;
                }
                a[i] = ai;
            } else { // even index -> put positive
                // need a[i] > max_{t=0..i-1}( s[t] - s[i-1] )
                long long max_before = prefMax[i-1];
                long long base_need = max_before - s[i-1]; // a[i] > base_need
                long long ai;
                if(i < n) {
                    // also ensure next negative can be -1 -> stronger: a[i] >= base_need + 2
                    ai = base_need + 2;
                } else {
                    // last element: minimal a[i] > base_need
                    ai = base_need + 1;
                }
                // ai must be at least 1 (positive), but base_need+1/+2 already guarantees positive normally
                if(ai <= 0) ai = 1;
                a[i] = ai;
            }
            s[i] = s[i-1] + a[i];
            prefMax[i] = max(prefMax[i-1], s[i]);
        }

        // output a[1..n]
        for(int i=1;i<=n;i++){
            if(i>1) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
    return 0;
}
