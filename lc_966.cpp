#include<bits/stdc++.h>
using namespace std;

#define int long long

string toLower(string s);
string deVowel(string s);
bool isVowel(char c);

string toLower(string s) {
    for(char &c : s) c = tolower(c);
    return s;
}

string deVowel(string s) {
    for(char &c : s) {
        if(isVowel(c)) c = '*';
    }
    return s;
}

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> wordlist(n);
    for(int i = 0; i < n; i++)
        cin >> wordlist[i];

    vector<string> queries(m);
    for(int i = 0; i < m; i++)
        cin >> queries[i];

    unordered_set<string> exact(wordlist.begin(), wordlist.end());
    unordered_map<string, string> caps;
    unordered_map<string, string> vowel;

    for(string w : wordlist) {
        string lower = toLower(w);
        string devowel = deVowel(lower);
        if(!caps.count(lower)) caps[lower] = w;
        if(!vowel.count(devowel)) vowel[devowel] = w;
    }
    vector<string> result;
    for(string q : queries) {
        if(exact.count(q))
            result.push_back(q);
        else {
            string lower = toLower(q);
            string devowel = deVowel(lower);

            if(caps.count(lower)) result.push_back(caps[lower]);
            else if(vowel.count(devowel)) result.push_back(vowel[devowel]);
            else result.push_back("");
        }
    }


    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    cout << '\n';
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
