#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void reverse(vector<int>& a,int start,int end){
    while(start<end){
        swap(a[start++],a[end--]);
    }
}

void CircularArrayRotation(vector<int>& a,int k){
    int n=a.size();
    k=k%n;

    reverse(a,0,n-1);
    reverse(a,0,k-1);
    reverse(a,k,n-1);
}

int main()
{
    vector<int> a={1,2,3,4,5};
    int k=2;

    cout<<"Original Array\n";
    for(int element:a){
        cout<<element<<" ";
    }
    cout<<'\n';

    CircularArrayRotation(a,k);

    cout<<"Rotated Array\n";
    for(int element:a){
        cout<<element<<" ";
    }
    cout<<'\n';

    return 0;
}
