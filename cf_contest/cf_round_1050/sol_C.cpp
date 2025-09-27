#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n; long long m;
        cin >> n >> m;
        vector<long long> a(n+1);
        vector<int> b(n+1);

        for(int i=0; i<n; i++) cin >> a[i] >> b[i];

        long long ans = 0;
        long long prev_t = 0;
        int prev_s = 0; // start at side 0

        for(int i=0; i<n; i++) {
            long long d = a[i] - prev_t;
            int need = prev_s ^ b[i];
            if(d % 2 == need) ans += d;
            else ans += d - 1;
            prev_t = a[i];
            prev_s = b[i];
        }

        // last free interval
        long long d = m - prev_t;
        ans += d; // can always use full interval
        cout << ans << "\n";
    }
}
