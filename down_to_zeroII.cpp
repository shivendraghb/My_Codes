#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    /*
        take a & b such that aXb = n
        change N to max(a,b)
        decrease N by 1
        MINIMIZE
    */
    /*
      can use a queue, pq will distort the order
      constraints allow for n^2

      can use pair for the number
      and the number of steps

      to minimize should use max for divisibilty check
    */

    /*
        this is like a shortest path problem in an implicit graph
        Nodes = int from 0 to n
        Edges = valid moves (either n -> n - 1 or n->max(a,b) if a*b=n)
        Goal = shortest path from node n to node 0
        like BFS
    */
    if(n <= 3){cout << n << '\n'; return;}

    queue<pair<int, int>> q;
    q.push({n, 0});
    int d;
    while(!q.empty()) {
        n = q.front().first;
        d = q.front().second;
        q.pop();

        if(n == 2) {
            cout << d + 2 << '\n';
            return;
        }

        q.push({n - 1, d + 1});

        //check for the divisibility
        int i = 2;
        while(i * i <= n) {
            if(n % i == 0)
                q.push({max(i, n / i), d + 1});
            i++;
        }
    }

    cout << -1 << '\n';
    return;
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
