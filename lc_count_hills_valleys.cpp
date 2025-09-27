#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int c = 0;

    for(int i = 1; i <= n - 2; i++) {
        if (v[i] == v[i - 1])
                continue;

        int j = i - 1, k = i + 1;
        while(j >= 0 && v[i] == v[j])
            j--;
        while(k < n && v[i] == v[k])
            k++;

        if (j >= 0 && k < n) {
            if ((v[i] > v[j] && v[i] > v[k]) || (v[i] < v[j] && v[i] < v[k]))
                c++;
        }

    }
    cout << c << '\n';
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
