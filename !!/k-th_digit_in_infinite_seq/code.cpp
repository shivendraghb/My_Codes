// #include <iostream>
// #include <string>
// #include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int findkthdigit(int k){
    if(k >= 1 && k <= 9) return k;

    long long digits = 1;
    long long count = 9;
    long long start = 1;

    while(true){
        long long total_digits = digits * count;
        if(k > total_digits){
            k -= total_digits;
            digits++;
            count *= 10;
            start *= 10;
        } else break;
    }

    long long number = start + (k - 1)/digits;
    string numstr = to_string(number);
    return numstr[(k - 1) % digits] - '0';
}

int main(){
    cout<<"k = 190, output: "<<findkthdigit(190)<<endl;
    cout<<"k = 11, output: "<<findkthdigit(11)<<endl;

    return 0;
}
