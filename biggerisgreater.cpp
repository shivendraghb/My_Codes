#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string w;
    cin >> w;

    int i = w.size() - 2;
    
    while(i >= 0 && w[i] >= w[i + 1]) {
        i--;
    }
    cout << "i=" << i << " ";

    if(i < 0) { cout << "no answer\n"; return; }

    int j = w.size() - 1;
    while(w[j] <= w[i]) {
        j--;
    }
    cout << "j=" << j << " ";
    cout << w << " ";

    swap(w[i], w[j]);

    cout << w << " ";
    reverse(w.begin() + i + 1, w.end());

    cout << w << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
        cout << "-----------" << '\n';
    }

    return 0;
}