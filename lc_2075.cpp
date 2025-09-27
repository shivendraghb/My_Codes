#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(string s, int row) {

    if(row == 1) {
        cout << s << '\n';
        return;
    }

    //find the number of columns
    //build the matrix and place the encodedtext
    //traverse the matrix to decode the original text

    //cols total number of whole letters + 1
    int col = (s.size() + row - 1) / row;

    //build the matrix
    int k = 0;
    vector<vector<int>> v(row, vector<int>(col));
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(k < s.size())
                v[i][j] = s[k++];
        }
    }

    //decode the original text
    string res = "";
    for(int c = 0; c < col; c++) {
        int r = 0, cc = c;
        while(r < row && cc < col) {
            res += v[r][cc];
            r++;
            cc++;
        }
    }

    cout << res << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    int t;
    cin >> t;

    while(t--) {
        int row;
        cin >> row;

        solve(s, row);
    }

    return 0;
}
