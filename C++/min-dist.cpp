#include<iostream>
int main()
{
    int a[]={3,5,4,2,6,5,6,8,3,2};
    int n=sizeof(a)/sizeof(a[0]);
    int x1=0,i1=-1,x2=8,i2=-1;
    int mindist=n;
    for(int i=0;i<n;i++)
    {
        if(a[i]==x1) i1=i;
        else if(a[i]==x2) i2=i;

        if(i1!=-1 && i2!=-1) mindist=(mindist>abs(i1-i2))? abs(i1-i2):mindist;
    }
    std::cout<<mindist<<'\n';
}
