#include<bits/stdc++.h>
using namespace std;

#define int long long

int pylons(int k, vector<int>& v) {
    int n = v.size();
    int i = 0, c = 0;

    while(i < n) {
        int pos = min(n - 1, i + k - 1);
        while(pos >= i - (k - 1) && (pos >= 0 && v[pos] == 0))
            pos--;

        if(pos < i - (k - 1) || pos < 0)
            return -1;

        c++;
        i = pos + k;
    }

    return c;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    cout << pylons(k, v) << "\n";

    return 0;
}
