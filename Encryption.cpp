#include <bits/stdc++.h>

using namespace std;

string encryption(string s) {
    string modified;

    for(char c : s){
        if(c != ' ')
            modified += c;
    }
    int len = modified.size();
    int rows = floor(sqrt(len));
    int cols = ceil(sqrt(len));

    //if dimension is less than len then we
    //can increase rows to cols, since rows(floor) < cols(ceil)
    //so increasing rows is enough
    if(rows * cols < len)
        rows = cols;

    string result;

    for(int col = 0; col < cols; col++){
        for(int row = 0; row < rows; row++){
            int index = row * cols + col;
            if(index < len)
                result += modified[index];
        }
        if(col != cols - 1)
            result += ' ';
    }
    return result;
}

int main()
{
    string s;
    getline(cin, s);

    string result = encryption(s);

    cout << result << "\n";

    return 0;
}
