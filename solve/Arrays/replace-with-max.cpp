#include<iostream>
int main()
{
    int a[]={3,5,4,2,6,5,6,8,3,2};
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=1;i<n;i++)
    {
        int max=a[i];
        for(int j=i+1;j<n;j++)
        {
            if(a[j]>max)
            max=a[j];
        }
        a[i-1]=max;
    }
    a[n-1]=-1;

    for(int element:a)
    {
        std::cout<<element<<" ";
    }
    std::cout<<'\n';
}
