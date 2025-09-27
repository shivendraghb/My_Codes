#include<stdio.h>
void frequency(int a[],int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        max = a[i];
    }
    int count[max+1];
    for(int i=0;i<=max;i++)
    {
        count[i]=0;
    }
    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }
    for(int i=0;i<=max;i++)
    {
        if(count[i]>0)
        printf("element %d is repeating %d times\n",i,count[i]);
    }
}
int main()
{
    int a[]={1,1,3,5,2,2,2,5,6,4,4,0,6,9,9,7,7};
    int n=sizeof(a)/sizeof(a[0]);
    frequency(a,n);
    return 0;
}
