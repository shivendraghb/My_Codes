#include<bits/stdc++.h>
using namespace std;

#define int long long

void minimumBribes(vector<int> q) {
    int bribes = 0;
    bool chaotic = false;
    for (int i = q.size() - 1; i >= 0; i--) {
        if (q[i] - (i + 1) > 2) {
            chaotic = true;
            break;
        }
        for (int j = max(0, q[i] - 2); j < i; j++) {
            if (q[j] > q[i])
                ++bribes;
        }
    }
    if (chaotic)
        cout << "Too chaotic" << endl;
    else
        cout << bribes << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> q(n);
        for (int i = 0; i < n; ++i) {
            cin >> q[i];
        }
        minimumBribes(q);
    }
    return 0;
}
