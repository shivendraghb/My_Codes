#include<iostream>
int main()
{
    int a[]={5,2,4,6,1,3};
    int n=sizeof(a)/sizeof(a[0]);

    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }

    for(int element:a){
        std::cout<<element<<" ";
    }
    std::cout<<'\n';
    return 0;
}
