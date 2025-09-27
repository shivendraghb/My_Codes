#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        // if (k == 1 && s.find('1') != string::npos) {
        //     cout << "NO\n";
        //     continue;
        // }

        // int run = 0, maxRun = 0;
        // for (char c : s) {
        //     if (c == '1') {
        //         run++;
        //         maxRun = max(maxRun, run);
        //     } else run = 0;
        // }
        // if (maxRun >= k) {
        //     cout << "NO\n";
        //     continue;
        // }
        if(k == 1 && s.find('1') != string::npos) {
            cout << "NO\n";
            continue;
        }

        int run = 0, maxRun = 0;
        for(char c : s) {
            if(c == '1') {
                run++;
                maxRun = max(maxRun, run);
            } else run = 0;
        }
        if(maxRun >= k) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        vector<int> p(n);
        vector<int> zeros, ones;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') zeros.push_back(i);
            else ones.push_back(i);
        }

        int val = n;
        for (int idx : zeros) p[idx] = val--;
        for (int idx : ones)  p[idx] = val--;

        for (int i = 0; i < n; i++) cout << p[i] << " \n"[i==n-1];
    }
}
