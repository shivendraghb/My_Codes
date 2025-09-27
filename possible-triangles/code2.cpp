#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int triangles(int a[],int n){
    sort(a,a+n);
    int count=0;
    for(int i=n-1;i>=2;i--){
        int l=0,r=i-1;
        while(l<r){
            if(a[l]+a[r]>a[i]){
                count+=r-l;
                r--;
            }else{
                l++;
            }
        }
    }
    return count;
}

int main(){
    int a[]={8,3,2,4,7,6,5};
    int n=sizeof(a)/sizeof(a[0]);

    int result=triangles(a,n);
    cout<<result<<endl;

    return 0;
}
