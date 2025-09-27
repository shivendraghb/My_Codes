#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> parse_input_line() {
    string line;
    getline(cin, line);  // Read the entire line including [ and ]

    vector<int> result;
    int num = 0;
    bool reading = false;

    for (char ch : line) {
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
            reading = true;
        } else {
            if (reading) {
                result.push_back(num);
                num = 0;
                reading = false;
            }
        }
    }

    if (reading)  // Catch last number if at end
        result.push_back(num);

    return result;
}

void solve() {
    vector<int> a = parse_input_line();
    int n = a.size();

    unordered_set<int> s;
    unordered_set<int> prev;

    for (int i = 0; i < n; i++) {
        unordered_set<int> curr;
        curr.insert(a[i]);

        for (int x : prev)
            curr.insert(x | a[i]);

        for (int x : curr)
            s.insert(x);

        prev = move(curr);
    }

    cout << s.size() << '\n';
}

int32_t main() {
    int t;
    cin >> t;
    cin.ignore(); // Flush the newline after reading `t`

    while (t--) {
        solve();
    }

    return 0;
}
