#include <bits/stdc++.h>
using namespace std;

long long minSwaps(vector<int> &pos) {
    int m = pos.size();
    if (m <= 1) return 0;
    int mid = m / 2;
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        ans += abs(pos[i] - (pos[mid] - mid + i));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        vector<int> posA, posB;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') posA.push_back(i);
            else posB.push_back(i);
        }

        long long ansA = minSwaps(posA);
        long long ansB = minSwaps(posB);

        cout << min(ansA, ansB) << "\n";
    }
}
