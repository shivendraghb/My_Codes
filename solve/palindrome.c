#include<stdio.h>
int main()
{
    int n,rev=0,rem,original;
    printf("enter the number: ");
    scanf("%d",&n);
    original=n;
    while(n>0)
    {
        rem=n%10;
        rev=rev*10+rem;
        n/=10;
    }
    if (rev==original)
    printf("the number %d is a palindrome\n",original);
    else
    printf("the number %d is not a palindrome\n",original);

    return 0;
}
