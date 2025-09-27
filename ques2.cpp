#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix[0].size() - 1;
    int m = matrix.size() - 1;
    int top = 0;
    int right = n;
    int left = 0;
    int bottom = m;

    vector<int> res;

    while (top <= bottom && left <= right) {

        for (int i = left; i <= right; i++) {
            res.push_back(matrix[top][i]);
        }
        top++;


        for (int i = top; i <= bottom; i++) {
            res.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return res;
}

int main() {
    vector<vector<int>> matrix={
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<int> result=spiralOrder(matrix);

    cout<<"Spiral Order: ";
    for(int num:result){
        cout<<num<<" ";
    }
    cout<<endl;

    return 0;
}
