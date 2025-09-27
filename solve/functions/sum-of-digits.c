#include<stdio.h>
int sum_of_digits(int n)
{
    int rem,sum=0;
    while(n>0)
    {
        rem=n%10;
        sum=sum+rem;
        n/=10;
    }
    return sum;
}
int main()
{
    int n;
    printf("enter the number: ");
    scanf("%d",&n);
    int result=sum_of_digits(n);
    printf("%d\n",result);
    return 0;
}
