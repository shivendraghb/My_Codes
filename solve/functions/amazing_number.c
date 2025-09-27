#include<stdio.h>
int sum_p(int n)
{
    int rem,sum=0,p=1;
    while(n>0)
    {
        rem=n%10;
        sum=sum+rem;
        p=p*rem;
        n/=10;
    }
    if (sum==p)
    return 1;
    else
    return 0;
}
int main()
{
    int n;
    printf("enter the number: ");
    scanf("%d",&n);
    if(sum_p(n))
    printf("amazing number\n");
    else
    printf("not amazing number\n");
    return 0;
}
