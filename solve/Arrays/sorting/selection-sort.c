#include<stdio.h>
int main()
{
    int a[]={12,1,8,10,5,3},temp;
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            min=j;
        } 
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
