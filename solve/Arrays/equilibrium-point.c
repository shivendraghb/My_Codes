#include<stdio.h>
int findequilibrium(int a[],int n)
{
    int sum=0,sum1=0,sum2=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }//sum1 for left side and sum2 for right side
    for(int i=0;i<n;i++)
    {
        sum2=sum-sum1-a[i];
        if(sum1==sum2)
        {
            return i;
        }
        sum1+=a[i];
    }
    return -1;
}
int main()
{
    int a[]={-7,1,5,2,-4,3,0};
    int n=sizeof(a)/sizeof(a[0]);
    int result=findequilibrium(a,n);
    if(result!=-1)
    printf("%d\n",result);
    else
    return 0;
}
