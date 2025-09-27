#include<stdio.h>
int main()
{
    int n;
    double sum=0,i;
    printf("enter the value of n: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum=sum+1/i;
    }
    printf("sum of series is %f\n",sum);
    return 0;
}
