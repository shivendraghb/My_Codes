#include <stdio.h>
int main()
{
    long int n,sum=0,remainder;
    printf("enter a positive number: ");
    scanf("%ld",&n);
    while (n>0)
    {
        remainder=n%10;
        sum=sum+remainder;
        n/=10;
    }
    printf("sum=%ld\n",sum);
    return 0;
}
