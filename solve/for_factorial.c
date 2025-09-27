#include<stdio.h>
int main()
{
    int n,fact=1;
    printf("enter the number: ");
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        fact=fact*i;
    }
    printf("the factorial of %d is:%d\n",n,fact);
    return 0;
}
