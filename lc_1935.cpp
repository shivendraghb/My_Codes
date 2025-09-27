#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string text;
    getline(cin >> ws, text);

    string bl;
    cin >> bl;

    // Pure string version:
    // int cnt = 0;
    // bool ok = true;

    // for(int i = 0; i <= text.size(); i++) {
    //     if(i == text.size() || text[i] == ' ') {
    //         if(ok) cnt++;
    //         ok = true;
    //     } else {
    //         if(bl.find(text[i]) != string::npos)
    //             ok = false;
    //     }
    // }

    // cout << cnt << '\n';

    // Unordered_set + string version:
    // unordered_set<char> broken(bl.begin(), bl.end());

    // int cnt = 0;
    // bool ok = true;

    // for(int i = 0; i <= text.size(); i++) {
    //     if(i == text.size() || text[i] == ' ') {
    //         if(ok) cnt++;
    //         ok = true;
    //     } else {
    //         if(broken.count(text[i]))
    //             ok = false;
    //     }
    // }

    // cout << cnt << '\n';

    // stringstream + unordered_set version:
    // unordered_set<char> broken(bl.begin(), bl.end());

    // stringstream ss(text);
    // string word;
    // int cnt = 0;

    // while(ss >> word) {
    //     bool ok = true;
    //     for(char c : word) {
    //         if(broken.count(c)) {
    //             ok = false;
    //             break;
    //         }
    //     }
    //     if(ok) cnt++;
    // }

    // cout << cnt << '\n';

    // Only stringstream version:
    stringstream ss(text);
    string word;
    int cnt = 0;

    while(ss >> word) {
        bool ok = true;
        for(char c : bl) {
            if(word.find(c) != string::npos) {
                ok = false;
                break;
            }
        }
        if(ok) cnt++;
    }

    cout << cnt << '\n';
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
