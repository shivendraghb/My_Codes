#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string w = "";
    cin >> w;

    int n = w.size();
    unordered_set<string> s;
    int i = 0;
    while(i < n) {
        if(isdigit(w[i]) == false) {
            i++;
            continue;
        }
        string temp = "";
        while(i < n && isdigit(w[i])) {
            temp += w[i];
            i++;
        }
        int j = 0;
        while(j < temp.size() && temp[j] == '0')
            j++;
        temp = temp.substr(j);
        s.insert(temp);
    }

    cout << s.size() << '\n';
}

int32_t main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
