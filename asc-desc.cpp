#include<bits/stdc++.h>
// #include<iostream>
// #include<algorithm>
using namespace std;

int main(){
    int a[]={8,3,2,4,1,2,3,4};
    int k=4;
    int n=sizeof(a)/sizeof(a[0]);
    if(n<k){
        cout<<"not possible"<<endl;
        return 0;
    }
    //ascending order
    sort(a,a+k);
    //descending order
    sort(a+k,a+n,greater<int>());
    //print
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
