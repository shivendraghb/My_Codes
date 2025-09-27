#include<stdio.h>
int factorial(int a);
int main()
{
    int n,fact;
    printf("enter value for n: ");
    scanf("%d",&n);
    fact=factorial(n);
    printf("factorial of %d is %d\n",n,fact);
    return 0;
}
int factorial(int a)
{
    int first=1;
    for(int i=1;i<=a;i++)
    {
        first=first*i;
    }
    return first;
}
