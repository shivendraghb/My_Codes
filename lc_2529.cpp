#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int pos = 0, neg = 0;
    for (int x : v) {
        if (x > 0) pos++;
        else if (x < 0) neg++;
    }
    cout << max(pos, neg) << '\n';

    // sort(v.begin(), v.end());
    // int left = 0, right = n - 1;
    // while (left < n && v[left] < 0) left++;
    // while (right >= 0 && v[right] > 0) right--;
    // int negCount = left;
    // int posCount = n - (right + 1);
    // cout << max(negCount, posCount) << '\n';
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