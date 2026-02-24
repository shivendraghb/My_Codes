// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long

// vector<vector<int>> tree;
// vector<int> value;

// ll dfs(int node, ll current) {
//     if (node == -1)
//         return 0;

//     current = (current << 1) | value[node];

//     if (tree[node][0] == -1 && tree[node][1] == -1)
//         return current;

//     return dfs(tree[node][0], current) +
//            dfs(tree[node][1], current);
// }

// int32_t main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while (t--) {
//         int n;
//         cin >> n;

//         tree.assign(n + 1, vector<int>(2));
//         value.assign(n + 1, 0);

//         for (int i = 1; i <= n; i++)
//             cin >> value[i];

//         for (int i = 1; i <= n; i++)
//             cin >> tree[i][0] >> tree[i][1];

//         cout << dfs(1, 0) << '\n';
//     }

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<int>> tree;
vector<int> value;

ll dfs(int node, ll current) {
    if (node == -1)
        return 0;

    current = (current << 1) | value[node];

    if (tree[node][0] == -1 || tree[node][1] == -1)
        return current;

    return dfs(tree[node][0] + current) +
           dfs(tree[node][1] + current);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        tree.assign(n + 1, vector<int>(2));
        value.assign(n + 1, 0);

        for (int i = 1; i <= n; i++)
            cin >> value[i];

        for (int i = 1; i <= n; i++)
            cin >> tree[i][0] >> tree[i][1];

        cout << dfs(1, 0) << '\n';
    }

    return 0;
}