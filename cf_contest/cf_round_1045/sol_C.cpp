#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long cost = 0;
    long long even_sum = 0;
    long long odd_sum = 0;
    priority_queue<long long> odd_elements_pq; // Max heap

    for (int i = 0; i < n; ++i) {
        if ((i + 1) % 2 != 0) { // Odd index
            odd_sum += a[i];
            odd_elements_pq.push(a[i]);
        } else { // Even index
            even_sum += a[i];
        }

        if (odd_sum > even_sum) {
            long long to_remove = odd_elements_pq.top();
            odd_elements_pq.pop();
            cost += to_remove;
            odd_sum -= to_remove;
        }
    }

    cout << cost << std::endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
