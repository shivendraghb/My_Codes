#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    vector<vector<int>> v(9, vector<int>(9));
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            cin >> v[i][j];

    /*
        can simply check for each row and column
        and each 3x3 grid

        use 3 separate loops and check the conditions
        for each of them in the three loops

        unordered_set v/s set
        ---------------------
        set -> ordered BST so operations can be log(n)
               but it is still instant for 9x9

        unorderd_set -> based on hash table so O(1)
                        operations and look ups
    */

    //check rows
    for(int i = 0; i < 9; i++) {
        unordered_set<int> s;
        for(int j = 0; j < 9; j++) {
            int val = v[i][j];
            if(val == 0) continue;
            if(s.count(val)){
                cout << "false" << '\n';
                return;
            }
            s.insert(val);
        }
    }

    //check columns
    for(int j = 0; j < 9; j++) {
        unordered_set<int> s;
        for(int i = 0; i < 9; i++) {
            int val = v[i][j];
            if(val == 0) continue;
            if(s.count(val)){
                cout << "false" << '\n';
                return;
            }
            s.insert(val);
        }
    }

    //check 3x3 grids
    for(int i = 0 ; i < 9; i += 3) {
        for(int j = 0; j < 9; j += 3) {
            unordered_set<int> s;
            for(int k = 0; k < 3; k++) {
                for(int l = 0; l < 3; l++) {
                    int val = v[i + k][j + l];
                    if(val == 0) continue;
                    if(s.count(val)){
                        cout << "false" << '\n';
                        return;
                    }
                    s.insert(val);
                }
            }
        }
    }

    cout << "true" << '\n';
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
