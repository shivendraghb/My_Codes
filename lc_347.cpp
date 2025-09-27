#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    /*
        create a map and sort it by the frequency(values of keys)
        to do so need a custom comparator or a lambda function
    */
    /*
        if two or more keys have same frequencies then the one which is smaller
        will be given first because of how map works i.e, ascending keys
        To change this behaviour we can modify the comparator
    */
    map<int, int> mp;
    for(int x : v)
        mp[x]++;

    vector<pair<int, int>> freq(mp.begin(), mp.end());

    sort(freq.begin(), freq.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            // If both frequencies are equal, prefer positive key over negative one
            if ((a.first < 0) != (b.first < 0))
                return a.first > b.first;
            //return a.first > b.first;
        }
        return a.second > b.second;
    });

    for(int i = 0; i < k && i < freq.size(); i++) {
        cout << freq[i].first << " ";
    }
    cout << "-------";
    cout << '\n';

    // int n, k;
    // cin >> n >> k;

    // vector<int> a(n);
    // for(int i = 0; i < n; i++)
    //     cin >> a[i];

    // map<int, int> mp;
    // for(int x : a)
    //     mp[x]++;

    // vector<pair<int, int>> freq(mp.begin(), mp.end());

    // sort(freq.begin(), freq.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
    //     if(a.seconfd == b.second) {
    //         if((a.first < 0) != (b.first < 0))
    //             return a.first > b.first;
    //     }
    //     return a.second > b.second;
    // });

    // for(int i = 0; i < k && i < freq.size(); i++)
    //     cout << freq[i].first << " ";

    // cout << '\n';
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
