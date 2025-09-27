#include<stdio.h>
int main()
{
    int n;
    float sum=0;
    printf("enter the value of n: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        float fact=1;
        for(int j=1;j<=i;j++)
        {
            fact=fact*j;
        }
        sum=sum+i/fact;
    }
    printf("the sum of series is %f\n",sum);
    return 0;
}
