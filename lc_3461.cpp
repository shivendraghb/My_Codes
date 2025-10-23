#include<bits/stdc++.h>
using namespace std;

// #define int long long

void solve () {
    string s;
    cin >> s;

    auto hasSameDigits = [&](const string &t) {
        string s = t;

        while(true) {
            string temp = "";
            for(int i = 0; i + 1 < (int)s.size(); i++) {
                int sum = ((s[i] - '0') + (s[i + 1] - '0')) % 10;
                temp += char('0' + sum);
            }

            if(temp.size() <= 2) {
                return (temp.size() == 2 && temp[0] == temp[1]);
            }

            s = temp;
        }
    };

    if(hasSameDigits(s))
        cout << "true" << '\n';
    else
        cout << "false" << '\n';
}

int32_t main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}