#include<bits/stdc++.h>
using namespace std;

#define int long long

bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    for(int i = 0; i < 9; i++) {
        if(board[row][i] == c) return false;
        if(board[i][col] == c) return false;
        /*
            each subgrid is 3 rows x 3 cols
            the top left of the subgrid can be found with:
                startRow - (row / 3) * 3
                startCol - (row / 3) * 3
            integer division groups rows and cols into blocks of 3

            Now, to iterate all 9 cells of that subgrid, we can use a
            single index i from 0 to 8 and map it to (r, c)

            subRow = startRow + i / 3
            subCol = startCol + i % 3

            i = 0 → (0,0) offset
            i = 1 → (0,1) offset
            i = 3 → (1,0) offset
            … until all 9 are covered

            this complete loop can also be replaced by:

            for(int k = 0; k < 3; k++) {
                for(itn l = 0; l < 3; l++) {
                    int subRow = (row / 3) * 3 + k;
                    int subCol = (col / 3) * 3 + l;
                }
            }
        */
        int subRow = 3 * (row / 3) + i / 3;
        int subCol = 3 * (col / 3) + i % 3;

        if(board[subRow][subCol] == c) return false;
    }

    return true;
}

bool solve(vector<vector<char>>& board) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(board[i][j] == '.') {
                for(char c = '1'; c <= '9'; c++) {
                    if(isValid(board, i, j, c)) {
                        board[i][j] = c;
                        if(solve(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        vector<vector<char>> board = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
        };

        solveSudoku(board);

        for(auto &row : board) {
            for(auto &ch : row)
                cout << ch << " ";
            cout << '\n';
        }
    }

    return 0;
}
