#include<bits/stdc++.h>
using namespace std;

#define int long long

/*
    You are given an array A of integers.

    Operation allowed: choose any 3 consecutive
    elements and rotate them clockwise.

    Example: [a, b, c] → [c, a, b].

    Question: Can you transform the array into
    a sorted array (1, 2, …, n) using such rotations?
*/

string larrysArray(vector<int>& A) {
    if(A.size() == 2 && A[0] > A[1]) return "NO";

    else if(A.size() == 1 || A.size() == 0) return "YES";

    else {
        auto me = min_element(A.begin(), A.end());
        int idx = distance(A.begin(), me);
        A.erase(A.begin() + idx);
        if(idx % 2 != 0)
            swap(A[0], A[1]);
    }

    return larrysArray(A);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> A(n);
        for(int i = 0; i < n; i++)
            cin >> A[i];

        string res = larrysArray(A);

        cout << res << '\n';
    }

    return 0;
}
