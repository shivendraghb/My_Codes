#include <stdio.h>
#include <math.h>
int main()
{
    int n,temp,sum=0,rem;
    printf("enter the number: ");
    scanf("%d",&n);
    temp=n;
    while(n>0)
    {
        rem=n%10;
        sum+=pow(rem,3);
        n/=10;
    }
    if(sum==temp)
    printf("the number %d is an armstrong number\n",temp);
    else
    printf("the number %d is not an armstrong number\n",temp);
    return 0;
}
