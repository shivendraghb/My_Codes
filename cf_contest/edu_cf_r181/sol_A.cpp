#include <bits/stdc++.h>
using namespace std;

#define int long long

bool is_difficult(const string &s) {
    for (int i = 0; i + 2 < s.size(); i++) {
        if ((s[i] == 'F' && s[i + 1] == 'F' && s[i + 2] == 'T') ||
            (s[i] == 'N' && s[i + 1] == 'T' && s[i + 2] == 'T'))
            return true;
    }
    return false;
}

void solve() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    if (!is_difficult(s)) {
        cout << s << '\n';
        return;
    }

    reverse(s.begin(), s.end());
    if (!is_difficult(s)) {
        cout << s << '\n';
        return;
    }

    map<char, int> freq;
    for (char c : s) freq[c]++;

    string res;
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c != 'F' && c != 'N' && c != 'T') {
            res += string(freq[c], c);
            freq[c] = 0;
        }
    }

    res += string(freq['F'], 'F');
    res += string(freq['T'], 'T');
    res += string(freq['N'], 'N');

    if (is_difficult(res)) {
        res.clear();
        res += string(freq['N'], 'N');
        res += string(freq['F'], 'F');
        res += string(freq['T'], 'T');
    }

    cout << res << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
