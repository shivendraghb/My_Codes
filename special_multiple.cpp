#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    queue<long long> q;
    //start with the smallest possible candidate i.e, 9
    q.push(9);

    long long t1 = q.front();
    //queue maitains the FIFO order
    //Essentially, this is a Breadth-First Search (BFS)
    //on numbers built from digits 0 and 9
    //        9
    //     /    \
    //   90      99
    //  /  \    /   \
    // 900 909 990  999
    // .....
    while(t1 % n != 0) {
        q.pop();
        //append 0 : how : by multiplying by 10
        long long t2 = t1 * 10;
        //append 9 : how : by multiplying by 10 and adding 9
        t1 = t1 * 10 + 9;
        q.push(t2);
        q.push(t1);
        t1 = q.front();
    }

    cout << to_string(t1) << '\n';
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
