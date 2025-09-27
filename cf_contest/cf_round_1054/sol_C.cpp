#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    // while (t--) {
    //     int n, k;
    //     cin >> n >> k;
    //     vector<int> a(n);
    //     unordered_set<int> s;
    //     int cntk = 0, cnt0 = 0;
    //     for (int i = 0; i < n; i++) {
    //         cin >> a[i];
    //         if (a[i] == k) cntk++;
    //         if (a[i] == 0) cnt0++;
    //         s.insert(a[i]);
    //     }

    //     if (k == 0) {
    //         cout << cnt0 << "\n";
    //     } else {
    //         int missing = 0;
    //         for (int x = 0; x < k; x++) {
    //             if (!s.count(x)) missing++;
    //         }
    //         cout << max(missing, cntk) << "\n";
    //     }
    // }
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        unordered_set<int> s;
        int cntk = 0, cnt0 = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] == k) cntk++;
            if(a[i] == 0) cnt0++;
            s.insert(a[i]);
        }

        if(k == 0) cout << cnt0 << '\n';
        else {
            int miss = 0;
            for(int i = 0; i < k; i++)
                if(!s.count(i)) miss++;

            cout << max(miss, cntk) << '\n';
        }
    }
}
