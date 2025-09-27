#include <stdio.h>
#include <math.h>
int main()
{
    int n,temp,sum=0,rem;
    printf("enter the number: ");
    scanf("%d",&n);
    temp=n;
    for(;temp>0;temp/=10)
    {
        rem=temp%10;
        sum+=pow(rem,3);
    }
    if (sum==n)
    printf("the number %d is an armstrong number\n",n);
    else
    printf("the number is not an armstrong number\n");
    return 0;
}

