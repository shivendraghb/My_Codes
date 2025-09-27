#include<bits/stdc++.h>
using namespace std;

#define int long long

/*
    add vowels in a separate array and sort it

    replace characters in string s if it's a vowel from the new array

    to check i can create a vector of vowels and check if the char of s
    is present in the vector of vowels

    create a bool function to check
*/

bool contain(char target) {
    return string("AEIOUaeiou").find(target) != string::npos;
}

void solve() {
    string s;
    cin >> s;

    vector<char> v;
    for(int i = 0; i < s.size(); i++) {
        if(contain(s[i]))
            v.push_back(s[i]);
    }

    sort(v.begin(), v.end());

    int v_idx = 0;
    for(int i = 0; i < s.size(); i++) {
        if(contain(s[i]))
            s[i] = v[v_idx++];
    }

    cout << s << '\n';
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
