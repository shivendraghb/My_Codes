#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, target;
    cin >> n >> target;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    long long low=0, high=v.size(),mid;
        if(target > v[high-1]) {
            cout << high << '\n';
            return;
        }
    while(low <= high){
        mid = low + (high - low) / 2;

        if(v[mid] == target) {
            cout << mid << '\n';
            return;
        }
        else if(target < v[mid]) {
            high = mid-1;
        }
        else if(target > v[mid]) {
            low = mid + 1;
        }
    }
    cout << low << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}
