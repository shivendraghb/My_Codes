#include<stdio.h>
void bubblesort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]<a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int kthlargest(int a[],int n,int k)
{
    bubblesort(a,n);
    return a[k-1];
}
int main()
{
    int a[]={1,5,8,10,3,7,11};
    int n=sizeof(a)/sizeof(a[0]);
    int k;
    printf("enter the value of k: ");
    scanf("%d",&k);
    if(k<=n)
    {
        int answer=kthlargest(a,n,k);
        printf("the %dth largest element in the array is: %d\n",k,answer);
    }
    else
    return 0;
}
