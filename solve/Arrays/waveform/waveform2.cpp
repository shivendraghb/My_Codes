#include<iostream>
void swap(int &x,int &y){
    int temp=x;
    x=y;
    y=temp;
}
int main()
{
    int a[]={3,5,4,2,6,5,6,8,3,2};
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++){
        if(a[i]<a[i-1]) swap(a[i],a[i-1]);
        if(i<n-1 && a[i]<a[i+1]) swap(a[i],a[i+1]);
    }
    for(int element:a){
        std::cout<<element<<" ";
    }
    std::cout<<'\n';
    return 0;
}
